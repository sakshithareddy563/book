cmake_minimum_required(VERSION 3.16)
project(BookExample)

set(CMAKE_CXX_STANDARD 11)

add_executable(book_example main.cpp book.cpp)

target_include_directories(book_example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
