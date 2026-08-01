cmake_minimum_required(VERSION 3.10)

project(
  TicTacToe

  VERSION 1.0.0.0
  DESCRIPTION "Simple TicTacToe game"
  LANGUAGES C
)

set(AUTHOR_NAME shaun)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

add_executable(
  # Name of executable. Using project name.
  ${PROJECT_NAME}

  # Source of executable
  peripheral.c
  main.c
)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC "include"
)

