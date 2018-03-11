cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")
set(GEN_PRO_NAME "lab")
project(${GEN_PRO_NAME})

add_subdirectory("typerANDviewer")
add_subdirectory("generator")
set(CMAKE_EXE_COMPILE_FLAGS "-fopenmp=libiomp5 -lgomp")
set(CMAKE_EXE_LINKER_FLAGS "-fopenmp -lgomp")

add_library(${PROJECT_NAME}seq STATIC "sol.cpp")

add_executable(${PROJECT_NAME} "before_code.cpp")

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}seq)
#target_compile_features(${GEN_PRO_NAME} PUBLIC cxx_std_11)
