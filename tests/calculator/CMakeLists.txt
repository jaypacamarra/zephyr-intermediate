cmake_minimum_required(VERSION 3.20.0)

if(BOARD MATCHES "unit_testing")
    find_package(Zephyr COMPONENTS unittest REQUIRED HINTS $ENV{ZEPHYR_BASE})
    project(calculator_basic_test)

    target_sources(testbinary PRIVATE main.c calculator.c)
else()
    find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
    project(calculator_basic_test)

    target_sources(app PRIVATE main.c calculator.c)
endif()
