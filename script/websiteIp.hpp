#include <iostream> // For input/output operations
#include <string>   // To work with website names as text
#include <vector>   // To store multiple IP addresses if a website has them

#include "termcolor.hpp"
#include "indenting.hpp"
#pragma comment(lib, "ws2_32.lib")
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstring>

bool initializeNetwork() {
#ifdef _WIN32
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << findent << "WSAStartup failed: " << iResult << std::endl;
        return false;
    }
#endif
    return true;
}

void cleanupNetwork() {
#ifdef _WIN32
    WSACleanup();
#endif
}

void websiteIp() {
     std::cout << termcolor::bright_yellow;
     std::string websiteName;
    if (!initializeNetwork()) {
        std::cerr << findent << "Error || 06" << std::endl;
        return;
    }

    std::cout << findent << "Please enter  a website name :";
    std::cin >> websiteName;

    std::cout << findent << "\n---" << findent << "IP" << findent << "Lookup" << findent << "Results" << findent << "---" << std::endl;
    std::cout << findent << "Searching" << findent << "for" << findent << "IP" << findent << "addresses" << findent << "for:" << findent << websiteName << std::endl;
    addrinfo hints;
    addrinfo *res;
    addrinfo *p;
    char ipstr[INET6_ADDRSTRLEN];

    std::memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    int status = getaddrinfo(websiteName.c_str(), "http", &hints, &res);

    if (status != 0) {
        std::cerr << findent << "Error" << findent << "||" << findent << "06" << std::endl; // Custom error message
        cleanupNetwork();
        return;
    }

    bool foundAnyIp = false;
    std::cout << findent << "IP" << findent << "Addresses" << findent << "found:" << std::endl;

    for (p = res; p != NULL; p = p->ai_next) {
        void *addr;
        std::string ipVersion;

        if (p->ai_family == AF_INET) { // IPv4
            sockaddr_in *ipv4 = reinterpret_cast<sockaddr_in*>(p->ai_addr);
            addr = &(ipv4->sin_addr);
            ipVersion = "IPv4";
        } else if (p->ai_family == AF_INET6) { // IPv6
            sockaddr_in6 *ipv6 = reinterpret_cast<sockaddr_in6*>(p->ai_addr);
            addr = &(ipv6->sin6_addr);
            ipVersion = "IPv6";
        } else {
            continue;
        }

        if (inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr)) != NULL) {
            std::cout << findent << findent << "-" << findent << ipstr << findent << "(" << findent << ipVersion << findent << ")" << std::endl;
            foundAnyIp = true;
        }
    }

    if (!foundAnyIp) {
        std::cout << findent << findent << "No" << findent << "IP" << findent << "addresses" << findent << "found" << findent << "for" << findent << "this" << findent << "website." << std::endl;
    }
    freeaddrinfo(res);

	cleanupNetwork();
	std::cout << termcolor::bright_yellow;
}

