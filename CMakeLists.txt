cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(PicoTests)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project

include_directories("include")

add_executable(PicoTests
    src/DECAFF/main.cpp
    src/DECAFF/screen.cpp    
    src/DECAFF/graph.cpp    
    src/DECAFF/calculator.cpp
    
    src/drivers/ili9341.cpp
    src/drivers/keymatrix.cpp

    src/DECAFF/core/tokenizer.cpp
)

target_link_libraries(PicoTests pico_stdlib hardware_spi)

pico_add_extra_outputs(PicoTests)


