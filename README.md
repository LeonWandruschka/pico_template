# 🚀 C/C++ Template Project for Neovim and CMake

Welcome to the **C/C++ Template Project**, designed for seamless development with **VSCode, CLion and Neovim** and **CMake**. 
This template serves as a robust starting point for new projects, featuring:

- 📦 A basic **CMake** configuration
- 📝 A simple **C/C++ program**
<!-- - ⚡ A customized **Neovim configuration** for an enhanced coding experience -->

---

## 📖 Getting Started

This section will guide you through setting up the project on **Windows**, **Linux**, **macOS**, or using **Docker**.

### 🔧 Prerequisites

Ensure you have the following tools installed:

- **CMake** (version 3.16 or higher)
- **GCC or Clang Compiler**
- **VSCode, CLion or Neovim** (or any other preferred text editor)
- **Git** (for cloning the repository)
- **Embedded Compiler** (explained in Install Instructions)
- **Docker** (optional, for containerized development)

---

## 🖥️ Installation Instructions

### 🐧 For Linux

1. **Update Packages:**
   ```bash
   sudo apt update && sudo apt upgrade -y
   ```
2. **Install Dependencies:**
   ```bash
   sudo apt install build-essential tar gcc cmake git -y
   ```
3. **Install Embedded Compiler:**
   ```bash
   sudo apt install gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib -y
   ```
4. **Clone the Repository:**
   ```bash
   git clone https://github.com/LeonWandruschka/pico_template.git
   cd pico_template
   ```

### 🍏 For macOS

1. **Install Homebrew (if not installed):**
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```
2. **Install Dependencies:**
   ```bash
   brew install cmake clang git
   ```
3. **Install Embedded Compiler:**
   ```bash
   brew install gcc-arm-embedded
   ```
4. **Clone the Repository:**
   ```bash
   git clone https://github.com/your-username/pico_template.git
   cd pico_template
   ```

<!--### 🪟 For Windows

1. **Install Chocolatey (if not installed):**
   Run PowerShell as Administrator:
   
powershell
   Set-ExecutionPolicy Bypass -Scope Process -Force; `
   [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; `
   iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))

2. **Install Dependencies:**
   
powershell
   choco install cmake mingw git neovim -y

3. **Clone the Repository and Build:**
   
powershell
   git clone https://github.com/your-username/pico_template.git
   cd pico_template
   mkdir build && cd build
   cmake .. -G "MinGW Makefiles"
   mingw32-make
   ./main.exe

-->

---
## 🐳 Build and Run with Docker

If you prefer using **Docker** for a consistent development environment:

### 📥 1⃣ Build the Docker Image

For **ARM-based CPUs** (like Apple Silicon):
```bash
docker build -t pico_template --platform=linux/amd64 .
```

For **non-ARM CPUs**:
```bash
docker build -t pico_template .
```

### 🚀 2⃣ Run the Docker Container

For **ARM-based CPUs**:
```bash
docker run -it --rm --platform linux/x86_64 --name pico-dev -v ./:/home/linuxbrew/pico/ pico_template
```

For **non-ARM CPUs**:
```bash
docker run -it --rm --name pico-dev -v ./:/home/linuxbrew/pico/ pico_template
```

- **`-it`**: Interactive terminal
- **`--rm`**: Removes the container after exit
- **`-v`**: Mounts the current directory into the container
- **`pico_template`**: Docker image name

### 🗂️ 3⃣ Keeping the Container Running

For **ARM-based CPUs**:
```bash
docker run -dit --platform linux/x86_64 --name pico-dev -v ./:/home/linuxbrew/pico/ pico_template tail -f /dev/null
```

For **non-ARM CPUs**:
```bash
docker run -dit --name pico-dev -v ./:/home/linuxbrew/pico/ pico_template tail -f /dev/null
```

Then you can access it anytime:

```bash
docker exec -it pico-dev bash
```

---

## 📂 Project Structure

```
.
├── CMakeLists.txt       # CMake build configuration
├── src                  # Source code directory
│   └── main.c           # Sample C program
├── include              # Header files
└── build                # Build directory (created after compilation)
```

---

## ✍️ Usage

1. **Edit the code:**
   ```bash
   nvim src/main.c
   ```
2. **Build the project:**
   ```bash
   cmake -B build -S .
   cmake --build build
   ```
3. **Copy uf2 file to pico**

---

## 🤝 Contributing

We welcome contributions to improve this template. Feel free to fork the repository, create pull requests, or open issues.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/awesome-feature`)
3. Commit your changes (`git commit -m 'Add some feature'`)
4. Push to the branch (`git push origin feature/awesome-feature`)
5. Open a pull request

---

### 📜 Included Licenses:

- **MIT License** - for the main project
- **BSD 3-Clause License** - for the Pico SDK

For more details, refer to the [LICENSE](LICENSE) file.
