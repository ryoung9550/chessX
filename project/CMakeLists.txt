cmake_minimum_required(VERSION 2.7)
project(ChessX)

set(CMAKE_MAJOR_VERSION 0)
set(CMAKE_MINOR_VERSION .01)

set(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")

set(SOURCES
	${CMAKE_SOURCE_DIR}/src/main.cpp
	${CMAKE_SOURCE_DIR}/src/component/board_square.cpp
	${CMAKE_SOURCE_DIR}/src/component/game_board.cpp
	${CMAKE_SOURCE_DIR}/src/game_pieces/game_piece.cpp
	${CMAKE_SOURCE_DIR}/src/exceptions/board_exceptions.cpp
)

add_executable(chicken ${SOURCES})
target_include_directories(chicken PRIVATE ${INCLUDE_DIR})
