cmake_minimum_required(VERSION 3.25.2)

project(OutOfBound)

set(CXX_STANDARD 14)

#make compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#set common variables
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)
set(INCLUDE_DIR ${ROOT_DIR}/include)
set(SRC_DIR ${ROOT_DIR}/src)
set(SRC ${SRC_DIR}/main.cpp)

find_package(SDL2 REQUIRED)

if(NOT SDL2_FOUND)
    message(FATAL_ERROR "CANNOT FOUND SDL2")
endif()

message(${SDL2_INCLUDE_DIR})

add_compile_options(-O2)

include_directories(${INCLUDE_DIR} ${SDL2_INCLUDE_DIR}/..)
add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME}
    ${SDL2_LIBRARIES}
)