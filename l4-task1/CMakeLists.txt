cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(l4-task1)

target_sources(app PRIVATE
        src/main.c
        src/sensor.c
        src/logger.c
        src/display.c
)

target_include_directories(app PRIVATE include)
