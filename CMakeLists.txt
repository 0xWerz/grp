cmake_minimum_required(VERSION 3.10)
project(grp)

set(CMAKE_CXX_STANDARD 11)

find_library(CRYPT_LIBRARY crypt)

add_executable(grp
    src/main.cpp
    src/pwd_generator.cpp
    src/pwd_generator.h
)

target_link_libraries(grp ${CRYPT_LIBRARY})
install(TARGETS grp DESTINATION bin)
# Add the following lines to build in a 'build/' folder in the same directory where CMake is run
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})