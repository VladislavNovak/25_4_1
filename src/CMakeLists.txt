cmake_minimum_required(VERSION 3.25)

add_executable(
        25_4_1 main.cpp
        ${INCLUDE_PATH}/surgical.h surgical.cpp
        ${INCLUDE_PATH}/utility.h utility.cpp)

target_include_directories(25_4_1 PUBLIC ${INCLUDE_PATH})