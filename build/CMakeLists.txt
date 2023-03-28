cmake_minimum_required(VERSION 3.25.2)

project(OutOfBound)

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)
set(SRC_DIR ${ROOT_DIR}/src)

set(SRC ${SRC_DIR}/main.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME}
    ${SDL2_LIBRARIES}
)