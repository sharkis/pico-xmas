cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(xmas)
pico_sdk_init()
add_executable(xmas
	xmas.c
)

target_link_libraries(xmas pico_stdlib hardware_pio)
pico_add_extra_outputs(xmas)

