cmake_minimum_required(VERSION 3.16)
project(trash)

set(PROJECT_LIB ${PROJECT_LIB} ${Boost_LOG_LIBRARY} ${Boost_LOG_SETUP_LIBRARY})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC -fopenmp  -DBOOST_LOG_DYN_LINK")

find_package(nlohmann_json 3.2.0 REQUIRED)


include_directories(${CMAKE_SOURCE_DIR}/config.json)  

add_executable(${PROJECT_NAME} trash.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
