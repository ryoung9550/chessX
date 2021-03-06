cmake_minimum_required(VERSION 2.7)
project(ChessX)

message(STATUS "CMAKE_SYSTEM_NAME          = ${CMAKE_SYSTEM_NAME}"         )
message(STATUS "CMAKE_CXX_COMPILER_ID      = ${CMAKE_CXX_COMPILER_ID}"     )
message(STATUS "CMAKE_CXX_COMPILER_VERSION = ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "CMAKE_COMPILER_IS_GNUCXX   = ${CMAKE_COMPILER_IS_GNUCXX}"  )

set(CMAKE_MAJOR_VERSION 0)
set(CMAKE_MINOR_VERSION .01)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../include)
set(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../src/)
set(MAIN_TARGET "chicken")

find_package(SDL2 REQUIRED)
#find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
#include_directories(${SDL2_IMAGE_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -Wextra")

set(SOURCES
	${CMAKE_SOURCE_DIR}/main.cpp
	${CMAKE_SOURCE_DIR}/chess/board_square.cpp
	${CMAKE_SOURCE_DIR}/chess/game_board.cpp
	${CMAKE_SOURCE_DIR}/chess/game_piece.cpp
	${CMAKE_SOURCE_DIR}/chess/rule_enforcer.cpp
	${CMAKE_SOURCE_DIR}/exceptions/board_exceptions.cpp
	${CMAKE_SOURCE_DIR}/exceptions/SDL_exceptions.cpp
	${CMAKE_SOURCE_DIR}/media/window.cpp
	${CMAKE_SOURCE_DIR}/media/io.cpp
	${CMAKE_SOURCE_DIR}/media/texture.cpp
	${CMAKE_SOURCE_DIR}/media/SDLDeleter.cpp
	${CMAKE_SOURCE_DIR}/media/draw_object.cpp
	${CMAKE_SOURCE_DIR}/common/pos.cpp
)

add_executable(${MAIN_TARGET} ${SOURCES})

target_include_directories(chicken PRIVATE ${INCLUDE_DIR})
target_link_libraries(${MAIN_TARGET} ${SDL2_LIBRARIES} SDL2_image)
