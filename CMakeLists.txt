# cmake_minimum_required(VERSION <specify CMake version here>)
project(towers_of_hanoi)
cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${towers_of_hanoi_SOURCE_DIR}/cmake")
set(BIN_DIR ${towers_of_hanoi_SOURCE_DIR}/bin)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(towers_of_hanoi main.cpp TowersOfHanoi.cpp)
target_link_libraries(towers_of_hanoi ${SDL2_LIBRARY})
install(TARGETS towers_of_hanoi RUNTIME DESTINATION ${BIN_DIR})