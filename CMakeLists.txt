cmake_minimum_required(VERSION 3.16)
project(BookExample)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_library(books STATIC book.cpp)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} books)
