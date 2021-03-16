cmake_minimum_required(VERSION 3.10)

project(smtc_tests C ASM)

set(CMAKE_C_STANDARD 99)

get_target_property(LFS_INCLUDES lfs INCLUDE_DIRECTORIES)

get_target_property(LFS_OPTS lfs COMPILE_OPTIONS)

get_target_property(LFS_DEFS lfs COMPILE_DEFINITIONS)

set(
TEST_SOURCES
${CMAKE_CURRENT_SOURCE_DIR}/smtc_tests.c
${CMAKE_CURRENT_SOURCE_DIR}/acl_mgr.c
${CMAKE_CURRENT_SOURCE_DIR}/card_format.c
${CMAKE_CURRENT_SOURCE_DIR}/crc.c
${CMAKE_CURRENT_SOURCE_DIR}/security_regions_mgr.c
${CMAKE_CURRENT_SOURCE_DIR}/storage_mgr.c
)

add_executable(smtc_tests ${TEST_SOURCES} ${LFS_INCLUDES})

target_compile_options(smtc_tests PRIVATE ${LFS_OPTS} -Wno-jump-misses-init)

target_compile_definitions(smtc_tests PRIVATE ${LFS_DEFS})

target_link_libraries(smtc_tests lfs)
