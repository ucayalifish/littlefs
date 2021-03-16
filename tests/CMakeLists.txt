cmake_minimum_required(VERSION 3.10)

project(lfs_alloc_tests C)

set(CMAKE_C_STANDARD 99)

get_target_property(LFS_INCLUDES lfs INCLUDE_DIRECTORIES)

message(STATUS ${LFS_INCLUDES})

get_target_property(LFS_OPTS lfs COMPILE_OPTIONS)

message(STATUS ${LFS_OPTIONS})

set(TEST_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/test_alloc.toml.bd.lfs_filebd.c
        ${CMAKE_CURRENT_SOURCE_DIR}/test_alloc.toml.bd.lfs_rambd.c
        ${CMAKE_CURRENT_SOURCE_DIR}/test_alloc.toml.bd.lfs_testbd.c
        ${CMAKE_CURRENT_SOURCE_DIR}/test_alloc.toml.lfs.c
        ${CMAKE_CURRENT_SOURCE_DIR}/test_alloc.toml.lfs_util.c
        ${CMAKE_CURRENT_SOURCE_DIR}/test_alloc.toml.test.c)

add_executable(lfs_alloc_tests ${TEST_SOURCES} ${LFS_INCLUDES})

target_compile_definitions(lfs_alloc_tests PRIVATE
        LFS_BLOCK_COUNT=1024
        LFS_BLOCK_CYCLES=-1
        LFS_BLOCK_SIZE=512
        LFS_CACHE_SIZE=64
        LFS_ERASE_VALUE=255
        LFS_LOOKAHEAD_SIZE=16
        LFS_PROG_SIZE=16
        LFS_READ_SIZE=16
        )

target_compile_options(lfs_alloc_tests PRIVATE ${COMPILE_OPTIONS} -MMD)
set_target_properties(lfs_alloc_tests PROPERTIES LINKER_LANGUAGE C)

target_link_libraries(lfs_alloc_tests lfs)
