cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "-std=c++17 -O3")
set(GEN_PRO_NAME "checker")
project(${GEN_PRO_NAME})

add_library(${PROJECT_NAME}lib STATIC "classResult.cpp")

set(CMAKE_EXE_LINKER_FLAGS "-static ../../../../Tools/mingw530_32/bin/libgcc_s_dw2-1.dll -static ../../../../Tools/mingw530_32/bin/libstdc++-6.dll")

add_executable(${PROJECT_NAME} checker.cpp)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}lib)
target_compile_features(${GEN_PRO_NAME} PUBLIC cxx_std_17)
