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

set(RAYLIB_PATH "D:/src/raylib/src")
set(RAYGUI_PATH "D:/src/raygui/src")

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC "include"
  PUBLIC ${RAYLIB_PATH}
  PUBLIC ${RAYGUI_PATH}
)

target_link_directories(
  ${PROJECT_NAME}
  PUBLIC ${RAYLIB_PATH}
)

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC raylib opengl32 gdi32 winmm
)

