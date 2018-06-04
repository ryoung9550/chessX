#pragma once

#include <array>
#include <memory>

#include "../component/board_square.h"
#include <component/board_square.h>
#include <common/globals.h>

class GameBoard
{
	BoardSquare* board;
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

