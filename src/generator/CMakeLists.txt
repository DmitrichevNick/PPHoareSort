cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "-std=c++17 -O3")
set(GEN_PRO_NAME "generator")
project(${GEN_PRO_NAME})

add_library(${PROJECT_NAME}lib STATIC "genfunc.cpp")

add_executable(${PROJECT_NAME} "generator.cpp" )

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}lib)
#target_compile_features(${GEN_PRO_NAME} PUBLIC cxx_std_17)
