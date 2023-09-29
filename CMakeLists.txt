cmake_minimum_required(VERSION 3.16)
project(BookExample)

set(CMAKE_CXX_STANDARD 17)
set(Boost_USE_STATIC_LIBS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")
set(PROJECT_LIB ${PROJECT_LIB} ${Boost_LOG_LIBRARY} ${Boost_LOG_SETUP_LIBRARY})
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC -fopenmp  -DBOOST_LOG_DYN_LINK")

find_package(libbsoncxx REQUIRED)
find_package(libmongocxx REQUIRED)
find_package(Boost COMPONENTS program_options log log_setup REQUIRED)

include_directories(.)
include_directories(${LIBMONGOCXX_INCLUDE_DIRS})
include_directories(${LIBBSONCXX_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

add_library(books book.cpp)
add_library(mongo database.cpp)
add_library(menu menu.cpp)

add_executable(${PROJECT_NAME} main.cpp book.cpp database.cpp menu.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBMONGOCXX_LIBRARIES} ${LIBBSONCXX_LIBRARIES})
target_link_libraries(${PROJECT_NAME} -Wl,--start-group  ${PROJECT_LIB} -Wl,--end-group)
target_include_directories(BookExample PUBLIC ${BOOST_INCLUDEDIR})
