cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(PicoTests)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project


add_executable(PicoTests
    src/main.cpp
    src/ili9341.cpp
    src/ili9341.h
    src/screen.h
    src/screen.cpp
    src/font.h
)

target_link_libraries(PicoTests pico_stdlib hardware_spi)

pico_add_extra_outputs(PicoTests)


