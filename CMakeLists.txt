cmake_minimum_required(VERSION 3.1)
project(design_pattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
	src
	src/creational_pattern
        src/behavioral_pattern
)

add_executable(${PROJECT_NAME} src/main.cpp)
