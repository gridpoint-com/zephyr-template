cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)

set(CPM_VERSION 0.40.2)
set(CPM_PATH "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_VERSION}.cmake")
if(NOT EXISTS ${CPM_PATH})
    message(STATUS "Downloading CPM.cmake to ${CPM_PATH}")
    set(CPM_GH_URL https://github.com/cpm-cmake/cpm.cmake/releases/download)
    set(CPM_RELEASE_URL ${CPM_GH_URL}/v${CPM_VERSION}/CPM.cmake)
    file(DOWNLOAD ${CPM_RELEASE_URL} ${CPM_PATH})
endif()
include(${CPM_PATH})

if(NOT DEFINED ENV{BOARD})
    message(FATAL_ERROR "Environment variable BOARD is not set. "
                        "See .envrc.example file for more details.")
endif()

set(BOARD_ROOT ${CMAKE_CURRENT_LIST_DIR})
get_filename_component(APP_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
set(CONFIG_KERNEL_BIN_NAME "\"${APP_NAME}[${BOARD}]\"" CACHE INTERNAL "The kernel binary name")
find_package(Zephyr $ENV{ZEPHYR_VERSION} REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(app)
set(SOURCES src/main.c)
target_sources(app PRIVATE ${SOURCES})
