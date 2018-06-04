#pragma once

#include <array>
#include <memory>

#include "board_square.h"
#include "globals.h"

class GameBoard
{
	std::array<BoardSquare, 12> board;
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

