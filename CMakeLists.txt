cmake_minimum_required(VERSION 3.9)
project(battlecity)

set(CMAKE_CXX_STANDARD 17)

add_executable(pong main.cpp map/map.cpp map/map.h global.cpp global.h movil/bola/bola.cpp movil/bola/bola.h movil/pala/pala.cpp movil/pala/pala.h interface/ncurses/ncurses.cpp interface/ncurses/ncurses.h keys/keys.cpp keys/keys.h)

target_link_libraries(pong ncursesw)