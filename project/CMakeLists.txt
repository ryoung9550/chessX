cmake_minimum_required(VERSION 2.7)
project(ChessX)

message(STATUS "CMAKE_SYSTEM_NAME          = ${CMAKE_SYSTEM_NAME}"         )
message(STATUS "CMAKE_CXX_COMPILER_ID      = ${CMAKE_CXX_COMPILER_ID}"     )
message(STATUS "CMAKE_CXX_COMPILER_VERSION = ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "CMAKE_COMPILER_IS_GNUCXX   = ${CMAKE_COMPILER_IS_GNUCXX}"  )

set(CMAKE_MAJOR_VERSION 0)
set(CMAKE_MINOR_VERSION .01)

set(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(MAIN_TARGET "chicken")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")

set(SOURCES
	${CMAKE_SOURCE_DIR}/src/main.cpp
	${CMAKE_SOURCE_DIR}/src/component/board_square.cpp
	${CMAKE_SOURCE_DIR}/src/component/game_board.cpp
	${CMAKE_SOURCE_DIR}/src/game_pieces/game_piece.cpp
	${CMAKE_SOURCE_DIR}/src/exceptions/board_exceptions.cpp
	${CMAKE_SOURCE_DIR}/src/exceptions/SDL_exceptions.cpp
	${CMAKE_SOURCE_DIR}/src/media/window.cpp
	${CMAKE_SOURCE_DIR}/src/media/texture.cpp
	${CMAKE_SOURCE_DIR}/src/media/SDLDeleter.cpp
	${CMAKE_SOURCE_DIR}/src/media/draw_object.cpp
)

add_executable(${MAIN_TARGET} ${SOURCES})

target_include_directories(chicken PRIVATE ${INCLUDE_DIR})
target_link_libraries(${MAIN_TARGET} ${SDL2_LIBRARIES})
