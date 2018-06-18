cmake_minimum_required(VERSION 3.9)
project(battlecity)

set(CMAKE_CXX_STANDARD 17)

add_executable(pong pong.cpp map.cpp map.h)

target_link_libraries(pong ncursesw)