# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Hello_world C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()
# Add executable. Default name is the project name, version 0.1

add_executable(Hello_world)

pico_generate_pio_header(Hello_world ${CMAKE_CURRENT_LIST_DIR}/hello.pio)

pico_set_program_name(Hello_world "Hello_world")
pico_set_program_version(Hello_world "0.1")

target_sources(Hello_world PRIVATE Hello_world.cpp)

# Modify the below lines to enable/disable output over UART/USB
# pico_enable_stdio_uart(Hello_world 0)
pico_enable_stdio_usb(Hello_world 1)

# Add the standard library to the build
target_link_libraries(Hello_world pico_stdlib hardware_dma pico_multicore hardware_pio)

target_compile_definitions(Hello_world PRIVATE
  PICO_DEFAULT_FLOAT_IMPL=pico 
  PICO_DEFAULT_DOUBLE_IMPL=pico 
)

# Add the standard include files to the build
target_include_directories(Hello_world PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(Hello_world)

# add_custom_command(
#     TARGET Hello_world POST_BUILD
#     COMMAND picotool reboot -f
#     COMMENT "Rebooting the Pico into BOOTSEL mode..."
# )