cmake_minimum_required(VERSION 2.8)

set(GEN_PRO_NAME "lab")
project(${GEN_PRO_NAME})

add_subdirectory("typerANDviewer")

set(CMAKE_EXE_LINKER_FLAGS "-fopenmp -lgomp")
 
add_library(${PROJECT_NAME}seq STATIC "sol.cpp")

add_executable(${PROJECT_NAME} "before_code.cpp")

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}seq)
