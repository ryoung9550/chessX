#pragma once

#include "component/board_square.h"
#include "common/globals.h"

#include <array>
#include <memory>

class GameBoard
{
	std::array<std::shared_ptr<BoardSquare>, globals::BOARD_SIZE * globals::BOARD_SIZE> gameSquares;
public:
	/*
	 * @brief - Create new gameboard with gamesquare and all game pieces
	 */
	GameBoard();

	/*
	 * @brief - Return reference to square
	 */
	std::shared_ptr<BoardSquare> getSquare(const size_t& row, const size_t& col);
	
	
};

