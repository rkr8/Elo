cmake_minimum_required (VERSION 2.8)
project (Elo)

# get version number via git
exec_program (
    git ${CMAKE_CURRENT_SOURCE_DIR}
    ARGS describe
    OUTPUT_VARIABLE Elo_VERSION
)

configure_file (
    ${PROJECT_SOURCE_DIR}/src/BuildSettings.h.in
    ${PROJECT_BINARY_DIR}/build/BuildSettings.h
)

# copy other header files to build directory
file (
    COPY ${PROJECT_SOURCE_DIR}/src/
    DESTINATION ${PROJECT_BINARY_DIR}/build
    PATTERN "BuildSettings.h.in" EXCLUDE
)

install (
    DIRECTORY ${PROJECT_BINARY_DIR}/build/
    DESTINATION include/Elo
)
