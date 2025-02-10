FROM homebrew/brew

# Switch to root to update the system and install packages
USER root

# Update and Install dependencies
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y build-essential tar gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib

# Switch back to the brew user
USER linuxbrew

# Install packages using Homebrew
RUN brew install curl file git cmake gcc python3 doxygen ripgrep cmake git neovim llvm

# Clone your Neovim config
RUN git clone https://github.com/LeonWandruschka/nvim-lua-config.git ~/.config/nvim

WORKDIR /home/linuxbrew/pico

# Set default command
CMD ["/bin/bash"]

