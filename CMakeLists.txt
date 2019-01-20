project (affinity_propagation)
cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -O3 -Wall -Wextra -std=c++17")

add_subdirectory(affinity_propagation)

add_executable(ap_test
               main.cpp
               )

target_link_libraries(ap_test aff_prop)
