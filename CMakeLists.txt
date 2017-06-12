#
# General
#

cmake_minimum_required (VERSION 2.8.2)
project (Elo)

#
# Options
#

option (
    BUILD_TESTS
    "Install Google Test and build all unit tests"
    OFF
)

#
# Version
#

# get version number via git
exec_program (
    git ${CMAKE_CURRENT_SOURCE_DIR}
    ARGS describe
    OUTPUT_VARIABLE Elo_VERSION
)

# write version number to BuildSettings.cpp
configure_file (
    ${PROJECT_SOURCE_DIR}/src/BuildSettings.cpp.in
    ${PROJECT_SOURCE_DIR}/src/BuildSettings.cpp
)

#
# Build Library
#

add_library (
    Elo
    ${PROJECT_SOURCE_DIR}/src/BuildSettings.cpp
    ${PROJECT_SOURCE_DIR}/src/Game.cpp
    ${PROJECT_SOURCE_DIR}/src/Player.cpp
)

#
# Installation
#

# install header files
install (
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION include/Elo
)

# install static library file
install (
    TARGETS Elo
    DESTINATION lib
)

#
# Google Test
#

# google test is optional
if (BUILD_TESTS)

    # Download and unpack googletest at configure time
    configure_file (CMakeLists.txt.in googletest-download/CMakeLists.txt)
    execute_process (
        COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download
    )
    if (result)
        message(FATAL_ERROR "CMake step for googletest failed: ${result}")
    endif (result)
    execute_process (COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download
    )
    if (result)
        message(FATAL_ERROR "Build step for googletest failed: ${result}")
    endif (result)

    # Prevent overriding the parent project's compiler/linker
    # settings on Windows
    set (gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    # This defines the gtest and gtest_main targets.
    add_subdirectory (
        ${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build
    )

    include_directories (${gtest_SOURCE_DIR}/include)

endif(BUILD_TESTS)

#
# Tests
#

# testing is optional
if (BUILD_TESTS)

    enable_testing ()

    include_directories (include)

    # Compile tests
    add_executable (
        exampleTest
        ${PROJECT_SOURCE_DIR}/tests/exampleTest.cpp
    )

    # Link google test library
    target_link_libraries (
        exampleTest
        gtest
        gtest_main
    )

    # Add test
    add_test (
        exampleTest
        exampleTest
    )

endif (BUILD_TESTS)
