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
  src/args.c
  src/peripheral.c
  src/state.c
  src/main.c
)

find_package(Curses REQUIRED)

add_executable(
  ${PROJECT_NAME}Ncurses

  src/main_ncurses.c
  src/args.c
  src/state.c
)

target_include_directories(
  ${PROJECT_NAME}Ncurses
  PRIVATE ${CURSES_INCLUDE_DIR}
)

target_link_libraries(
  ${PROJECT_NAME}Ncurses
  ${CURSES_LIBRARIES}
)

# Testing
enable_testing()
add_subdirectory(tests)

