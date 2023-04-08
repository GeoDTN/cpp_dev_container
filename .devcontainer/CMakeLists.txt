cmake_minimum_required(VERSION 3.16)
project(modern_cpp VERSION 0.0.0.1)
enable_testing()
add_executable(00001  src/cpp_0001.cpp)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 2a)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_CLANG_TIDY clang_tidy_11)
## TO DO
## add static analysis tools, valgrid, performance tunning, CI/CD, cloud ...