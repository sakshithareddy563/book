cmake_minimum_required(VERSION 3.16)
project(BookExample)

set(PROJECT_LIB ${PROJECT_LIB} ${Boost_LOG_LIBRARY} ${Boost_LOG_SETUP_LIBRARY})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC -fopenmp  -DBOOST_LOG_DYN_LINK")



find_package(libbsoncxx REQUIRED)
find_package(libmongocxx REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options log log_setup)

include_directories(${LIBMONGOCXX_INCLUDE_DIRS})
include_directories(${LIBBSONCXX_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/config.json)  

add_library(books book.cpp)
add_library(mongo database.cpp)
add_library(menu menu.cpp)
add_library(persons persons.cpp)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} books mongo menu persons)
target_link_libraries(${PROJECT_NAME} ${LIBMONGOCXX_LIBRARIES} ${LIBBSONCXX_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})


target_compile_definitions(${PROJECT_NAME} PRIVATE BOOST_LOG_DYN_LINK)

target_link_libraries(${PROJECT_NAME} -Wl,--start-group ${Boost_LOG_LIBRARY} ${Boost_LOG_SETUP_LIBRARY} -Wl,--end-group)
