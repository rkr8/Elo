#
# General
#

cmake_minimum_required (VERSION 2.8.2)
project (Elo)

#
# Version
#

# get version number via git
exec_program (
    git ${CMAKE_CURRENT_SOURCE_DIR}
    ARGS describe
    OUTPUT_VARIABLE Elo_VERSION
)

# write version number to header file
configure_file (
    ${PROJECT_SOURCE_DIR}/src/BuildSettings.h.in
    ${PROJECT_SOURCE_DIR}/include/BuildSettings.h
)

#
# Installation
#

install (
    DIRECTORY ${PROJECT_BINARY_DIR}/include/
    DESTINATION include/Elo
)

#
# Google Test
#

# Download and unpack googletest at configure time
configure_file (CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process (
    COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download
)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process (COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download
)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set (gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# This defines the gtest and gtest_main targets.
add_subdirectory (
    ${CMAKE_BINARY_DIR}/googletest-src
    ${CMAKE_BINARY_DIR}/googletest-build
)

include_directories (${gtest_SOURCE_DIR}/include)

#
# Tests
#

enable_testing ()

include_directories (include)

# TODO: Add tests
