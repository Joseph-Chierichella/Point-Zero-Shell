# Point Zero Shell
In terminal shell with functions like no other!
Point Zero Shell is an ongoing project that I am currently working on. I can use some help so if you want to make any changes please do.

## Copyright and Usage

All scripts and utilities in this repository are the intellectual property of Joseph Chierichella. They are provided under the terms of the [MIT License](LICENSE), which allows you to freely view, modify, and redistribute the code with proper attribution. Unauthorized use, reproduction, or misrepresentation of authorship is prohibited.

If you use or modify this code, please ensure proper attribution to the original author.

© Joseph Chierichella | All rights reserved

## Contributions

Contributions are welcome! Please feel free to fork the repository, make improvements, and submit pull requests. Ensure all changes align with the project’s goals and follow best practices for code quality and documentation. 

---

## 🔧 Installation & Usage

To use Point Zero Shell, ensure you have Git and the g++ compiler installed on your system.

### ✅ Install Git

**Linux (Debian/Ubuntu):**
```bash
sudo apt update
sudo apt install git
```

**macOS:**
```bash
brew install git
```

> Requires Homebrew: https://brew.sh

**Windows:**  
Download Git from https://git-scm.com/download/win and follow the installer instructions.

---

### ✅ Install g++

**Linux (Debian/Ubuntu):**
```bash
sudo apt update
sudo apt install g++
```

**macOS:**
```bash
brew install gcc
```

**Windows (via MSYS2):**
1. Download and install from https://www.msys2.org/
2. Open MSYS2 shell and run:
```bash
pacman -Syu
pacman -S mingw-w64-x86_64-gcc
```

---

### 📥 Clone and Compile

Clone the repo and navigate to it:

```bash
git clone https://github.com/Joseph-Chierichella/Point-Zero-Shell
cd Point-Zero-Shel
```

Then compile the `main.cpp` file:

**Linux / macOS:**
```bash
g++ main.cpp -o pointzero
./pointzero
```

**Windows (MSYS2 MinGW shell):**
```bash
g++ main.cpp -o pointzero.exe
./pointzero.exe
```
