cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(8bitprocessor C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(8bitprocessor
	main.c
	)

target_link_libraries(8bitprocessor pico_stdlib)


pico_enable_stdio_usb(8bitprocessor 1)
pico_enable_stdio_uart(8bitprocessor 1)

pico_add_extra_outputs(8bitprocessor)