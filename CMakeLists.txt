cmake_minimum_required(VERSION 3.10)

project(lfs C ASM)

set(CMAKE_C_STANDARD 99)

add_library(lfs lfs.c lfs_util.c bd/lfs_filebd.c bd/lfs_rambd.c bd/lfs_testbd.c)

target_include_directories(lfs PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(lfs PUBLIC -Wall -pedantic -Wextra -Wshadow -Wjump-misses-init -Wundef -Wno-unknown-warning-option)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimization for speed")
    target_compile_options(lfs PUBLIC -O2)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimization for speed, debug info included")
    target_compile_options(lfs PUBLIC -O2 -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimization for size")
    target_compile_options(lfs PUBLIC -Os)
else ()
    message(STATUS "Minimal optimization, debug info included")
    target_compile_options(lfs PUBLIC -Og -g)
    target_compile_definitions(lfs PUBLIC LFS_YES_TRACE)
endif ()
