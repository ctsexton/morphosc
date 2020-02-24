cmake_minimum_required(VERSION 3.10)

# set the project name
project(MorphOSC VERSION 0.1 LANGUAGES C)

configure_file(src/MorphOSCConfig.h.in MorphOSCConfig.h)

# add the executable
add_executable(MorphOSC src/main.c src/geometry.c)

target_include_directories(MorphOSC PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/src"
                           )
