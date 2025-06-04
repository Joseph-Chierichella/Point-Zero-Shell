#ifndef PORT_SCANNER_HPP
#define PORT_SCANNER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <limits>
#include <stdexcept>

#include "termcolor.hpp"
#include "indenting.hpp"

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <poll.h>
    #include <errno.h>
#endif

std::mutex g_mtx_scanner_output;

inline bool convertIpToBinary(const std::string& ipAddress, void* addr_buffer) {
#ifdef _WIN32
    return InetPton(AF_INET, ipAddress.c_str(), addr_buffer) == 1;
#else
    return inet_pton(AF_INET, ipAddress.c_str(), addr_buffer) == 1;
#endif
}

inline void scanSinglePort(const std::string& ipAddress, int port, int timeoutMilliseconds) {
    int sock = -1;
    struct sockaddr_in serverAddr;

    #ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::lock_guard<std::mutex> lock(g_mtx_scanner_output);
        std::cerr << findent << "WSAStartup failed for port " << port << ". Error || 03 || " << WSAGetLastError() << std::endl;
        return;
    }
    #endif

    try {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            std::lock_guard<std::mutex> lock(g_mtx_scanner_output);
            std::cerr << findent << "Error || 04 || " << port << std::endl;
            goto cleanup;
        }

        #ifdef _WIN32
        u_long iMode = 1;
        if (ioctlsocket(sock, FIONBIO, &iMode) != NO_ERROR) {
            std::lock_guard<std::mutex> lock(g_mtx_scanner_output);
            std::cerr << findent << "Error: ioctlsocket failed for port " << port << ". Error: " << WSAGetLastError() << std::endl;
            goto cleanup;
        }
        #else
        int flags = fcntl(sock, F_GETFL, 0);
        if (flags < 0) {
            std::lock_guard<std::mutex> lock(g_mtx_scanner_output);
            std::cerr << findent << "Error: Could not get socket flags for port " << port << std::endl;
            goto cleanup;
        }
        if (fcntl(sock, F_SETFL, flags | O_NONBLOCK) < 0) {
            std::lock_guard<std::mutex> lock(g_mtx_scanner_output);
            std::cerr << findent << "Error: Could not set non-blocking flag for port " << port << std::endl;
            goto cleanup;
        }
        #endif

        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(port);
        if (!convertIpToBinary(ipAddress, &serverAddr.sin_addr)) {
            std::lock_guard<std::mutex> lock(g_mtx_scanner_output);
            std::cerr << findent << "Error || 05 || " << ipAddress << std::endl;
            goto cleanup;
        }

        int connectResult = connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

        if (connectResult < 0) {
            #ifdef _WIN32
            int lastError = WSAGetLastError();
            if (lastError == WSAEINPROGRESS || lastError == WSAEWOULDBLOCK) {
            #else
            if (errno == EINPROGRESS) {
            #endif
                #ifdef _WIN32
                fd_set writeSet;
                FD_ZERO(&writeSet);
                FD_SET(sock, &writeSet);

                struct timeval tv;
                tv.tv_sec = timeoutMilliseconds / 1000;
                tv.tv_usec = (timeoutMilliseconds % 1000) * 1000;

                int selResult = select(0, NULL, &writeSet, NULL, &tv);
                #else
                struct pollfd pfd;
                pfd.fd = sock;
                pfd.events = POLLOUT;

                int selResult = poll(&pfd, 1, timeoutMilliseconds);
                #endif

                if (selResult > 0) {
                    #ifdef _WIN32
                    if (FD_ISSET(sock, &writeSet)) {
                    #else
                    if (pfd.revents & POLLOUT) {
                    #endif
                        int error = 0;
                        socklen_t len = sizeof(error);
                        if (getsockopt(sock, SOL_SOCKET, SO_ERROR, (char*)&error, &len) < 0) {
                            std::lock_guard<std::mutex> lock(g_mtx_scanner_output);
                            std::cerr << findent << "Error: getsockopt failed for port " << port << std::endl;
                        } else if (error == 0) {
                            std::lock_guard<std::mutex> lock(g_mtx_scanner_output);
                            std::cout << findent << "Port " << port << " is OPEN" << std::endl;
                        }
                    }
                }
            }
        } else {
            std::lock_guard<std::mutex> lock(g_mtx_scanner_output);
            std::cout << findent << "Port " << port << " is OPEN" << std::endl;
        }
    } catch (const std::exception& e) {
        std::lock_guard<std::mutex> lock(g_mtx_scanner_output);
        std::cerr << findent << "Exception scanning port " << port << ": " << e.what() << std::endl;
    }

cleanup:
    if (sock != -1) {
        #ifdef _WIN32
        closesocket(sock);
        #else
        close(sock);
        #endif
    }
    #ifdef _WIN32
    WSACleanup();
    #endif
}

inline void runPortScan() {
	std::cout << termcolor::bright_yellow;
    std::string ipAddress;
    int startPort, endPort;
    int timeoutSeconds = 1;

    std::cout << findent << "Simple Port Scanner" << std::endl;
    std::cout << findent << "Enter target IP address (e.g., 127.0.0.1): ";
    std::cin >> ipAddress;

    sockaddr_in sa;
    if (!convertIpToBinary(ipAddress, &sa.sin_addr)) {
        std::cerr << findent << "Error || 05" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << findent << "Enter starting port (1-65535): ";
    while (!(std::cin >> startPort) || startPort < 1 || startPort > 65535) {
        std::cout << findent << "Invalid input. Please enter a port number between 1 and 65535: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << findent << "Enter ending port (1-65535): ";
    while (!(std::cin >> endPort) || endPort < startPort || endPort > 65535) {
        if (endPort < startPort) {
            std::cout << findent << "Ending port must be greater than or equal to starting port (" << startPort << "): ";
        } else {
            std::cout << findent << "Invalid input. Please enter a port number between 1 and 65535: ";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << findent << "Enter connection timeout in seconds (default: 1, press Enter to use default): ";
    std::string timeoutInput;
    std::getline(std::cin, timeoutInput);
    if (!timeoutInput.empty()) {
        try {
            int parsedTimeout = std::stoi(timeoutInput);
            if (parsedTimeout > 0) {
                timeoutSeconds = parsedTimeout;
            } else {
                std::cout << findent << "Invalid timeout (must be > 0). Using default of 1 second.\n";
            }
        } catch (const std::invalid_argument&) {
            std::cout << findent << "Invalid timeout format. Using default of 1 second.\n";
        } catch (const std::out_of_range&) {
            std::cout << findent << "Timeout value too large. Using default of 1 second.\n";
        }
    }

    std::cout << findent << "Starting port scan on " << ipAddress << " from port "
              << startPort << " to " << endPort << " (timeout: " << timeoutSeconds << "s per port)" << std::endl;

    std::vector<std::thread> threads;
    for (int port = startPort; port <= endPort; ++port) {
        threads.emplace_back(scanSinglePort, ipAddress, port, timeoutSeconds * 1000);
    }

    for (std::thread& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    std::cout << findent << "Port scan complete.\n";
    std::cout << termcolor::reset;
}

#endif
