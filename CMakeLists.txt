cmake_minimum_required(VERSION 3.13)

# Set pico config infos
set(PICO_BOARD pico)
set(PICO_PLATFORM rp2040)
set(PICO_SDK_FETCH_FROM_GIT on)

# Include pico-sdk
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/pico_sdk_import.cmake)

# Set Project name to your liking. Leave LANGUAGES as is.
project(Pico LANGUAGES C CXX ASM)

# Create compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Source files
set(SOURCE_FILES
  # Place your source files here:
  main.c
)

# Hardware libraries
set(HARDWARE_LIBS
    pico_stdlib
)

message(STATUS "Host System Name: ${CMAKE_HOST_SYSTEM_NAME}")

# Detect ARM GCC system root differently based on OS
if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    # On Linux, set ARM_GCC_SYSROOT manually
    set(ARM_GCC_SYSROOT "/usr/lib/arm-none-eabi")
else()
    # On macOS or Windows, detect sysroot automatically
    execute_process(
        COMMAND arm-none-eabi-gcc -print-sysroot
        OUTPUT_VARIABLE ARM_GCC_SYSROOT
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
endif()
message(STATUS "Detected ARM GCC sysroot: ${ARM_GCC_SYSROOT}")

# Set build type
set(CMAKE_BUILD_TYPE Release)

# Initialize pico-sdk
pico_sdk_init()

# Source path
set(SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Prepend source path
list(TRANSFORM SOURCE_FILES PREPEND ${SOURCE_PATH}/)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${ARM_GCC_SYSROOT}/include)

# Set printf output
pico_enable_stdio_uart(${PROJECT_NAME} 0)
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_add_extra_outputs(${PROJECT_NAME})

# Link pico stdlib
target_link_libraries(${PROJECT_NAME} ${HARDWARE_LIBS})

# Add include path
target_compile_options(${PROJECT_NAME} PRIVATE -I${ARM_GCC_SYSROOT}/include)

# Testing functions using CMake
include(CTest)
