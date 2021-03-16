cmake_minimum_required(VERSION 3.10)

#set(CMAKE_VERBOSE_MAKEFILE ON)

project(lfs C ASM)

set(CMAKE_C_STANDARD 99)

set(LFS_SOURCES lfs.c lfs_util.c bd/lfs_filebd.c bd/lfs_rambd.c bd/lfs_testbd.c)

if ("${USE_MINGW}" STREQUAL "1")
    message(STATUS "Using MinGW toolset")
    set(LFS_SOURCES ${LFS_SOURCES} bd/fsync.c)
endif ()

add_library(lfs ${LFS_SOURCES})

target_include_directories(lfs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(lfs PUBLIC -Wall -Wextra -Wshadow -Wjump-misses-init -Wundef -Wno-unknown-warning-option -Wno-unknown-pragmas)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

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
#    target_compile_definitions(lfs PUBLIC ${COMPILE_DEFINITIONS} LFS_YES_TRACE)
endif ()

target_compile_definitions(lfs PUBLIC ${COMPILE_DEFINITIONS}  LFS_NO_MALLOC)

add_subdirectory(smtc_tests)

#[[
add_subdirectory(tests)
]]
