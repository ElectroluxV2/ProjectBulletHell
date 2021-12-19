cmake_minimum_required(VERSION 3.21)
project (ProjectBulletHell)

set(CMAKE_CXX_STANDARD 23)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)

add_executable(ProjectBulletHell main.cpp)

target_link_libraries(${PROJECT_NAME} SDL2::Main)
