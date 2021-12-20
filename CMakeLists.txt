cmake_minimum_required(VERSION 3.21)
project(ProjectBulletHell)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/sdl2)

add_executable(ProjectBulletHell main.cpp)

target_link_libraries(${PROJECT_NAME} SDL2)
