cmake_minimum_required(VERSION 4.3.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(lowerupperbracket
  VERSION 0.1.0
  LANGUAGES CXX
)

add_executable(lowerupperbracket
  src/main.cpp
  src/player.hpp
  src/match.hpp
)

