cmake_minimum_required(VERSION 2.8)

project(lab)

add_library(${PROJECT_NAME}sol STATIC "sol.cpp")
set(CMAKE_EXE_LINKER_FLAGS "-static ../../Tools/mingw530_32/bin/libgcc_s_dw2-1.dll -static ../../Tools/mingw530_32/bin/libstdc++-6.dll")
add_executable(${PROJECT_NAME} "before_code.cpp")
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}sol)
