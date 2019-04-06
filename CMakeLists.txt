cmake_minimum_required(VERSION 3.13)
project(CSV_TokenCutter C)

set(CMAKE_C_STANDARD 99)

add_library(CSV_TokenCutter SHARED CSV_TokenCutter.h CSV_TokenCutter.c)

find_library(char_at NAMES libChar_At.so PATHS ${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(CSV_TokenCutter ${char_at})