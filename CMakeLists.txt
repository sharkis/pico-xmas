cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(xmas)
pico_sdk_init()
add_executable(xmas
	xmas.c
)
pico_generate_pio_header(xmas ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/build/generated)

target_link_libraries(xmas pico_stdlib hardware_pio hardware_clocks)
pico_add_extra_outputs(xmas)

