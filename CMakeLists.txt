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

project(PicoFalcon C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()
# Add executable. Default name is the project name, version 0.1

add_executable(PicoFalcon)

# pico_generate_pio_header(Hello_world ${CMAKE_CURRENT_LIST_DIR}/hello.pio)

pico_set_program_name(PicoFalcon "PicoFalcon")
pico_set_program_version(PicoFalcon "0.1")

# Add all `.cpp` files in AccelStepperSDK/src and TMCStepperSDK/src to the target
file(GLOB ACCELSTEPPER_SRC ${CMAKE_CURRENT_SOURCE_DIR}/AccelStepperSDK/src/*.cpp)
file(GLOB TMCSTEPPER_SRC ${CMAKE_CURRENT_SOURCE_DIR}/TMCStepperSDK/src/source/*.cpp)
file(GLOB TMCSTEPPER_SRC_HAL ${CMAKE_CURRENT_SOURCE_DIR}/TMCStepperSDK/src/source/TMC_HAL/*.cpp)
file(GLOB TMCSTEPPER_SRC_INTERFACES ${CMAKE_CURRENT_SOURCE_DIR}/TMCStepperSDK/src/source/interfaces/*.cpp)

# Add those files to the target
target_sources(PicoFalcon PRIVATE main.cpp ${ACCELSTEPPER_SRC} ${TMCSTEPPER_SRC} ${TMCSTEPPER_SRC_HAL} ${TMCSTEPPER_SRC_INTERFACES})

# target_sources(PicoFalcon PRIVATE main.cpp AccelStepperSDK/src/AccelStepper.cpp AccelStepperSDK/src/AccelStepper.hpp TMCStepperSDK/src/TMCStepper.h)

# Modify the below lines to enable/disable output over UART/USB
# pico_enable_stdio_uart(Hello_world 0)
pico_enable_stdio_usb(PicoFalcon 1)

# Add the standard library to the build
target_link_libraries(PicoFalcon pico_stdlib hardware_dma pico_multicore hardware_pio hardware_spi)

target_compile_definitions(PicoFalcon PRIVATE
  PICO_DEFAULT_FLOAT_IMPL=pico 
  PICO_DEFAULT_DOUBLE_IMPL=pico 
)

# Add the standard include files to the build
target_include_directories(PicoFalcon PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(PicoFalcon)

# add_custom_command(
#     TARGET Hello_world POST_BUILD
#     COMMAND picotool reboot -f
#     COMMENT "Rebooting the Pico into BOOTSEL mode..."
# )