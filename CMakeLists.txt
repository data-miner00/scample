cmake_minimum_required(VERSION 3.10)

project(
  scample

  VERSION 1.0.0.0
  DESCRIPTION "I love C"
  LANGUAGES C
)

set(AUTHOR_NAME shaun)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

add_executable(
  # Name of executable. Using project name.
  ${PROJECT_NAME}

  # Source of executable
  main.c
)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC "include"
)
