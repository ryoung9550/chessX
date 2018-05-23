cmake_minimum_required(VERSION 2.7)
project(ChessX)

set(CMAKE_MAJOR_VERSION 0)
set(CMAKE_MINOR_VERSION .01)

set(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../)
include_directories(${CMAKE_SOURCE_DIR}/include/)

set(SOURCES
	${CMAKE_SOURCE_DIR}/src/main.cpp
	${CMAKE_SOURCE_DIR}/src/board_square.cpp
)

add_executable(chicken ${SOURCES})
