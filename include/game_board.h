#ifndef _GAME_BOARD_H
#define _GAME_BOARD_H

#include <array>
#include <memory>

#include <board_square.h>
#include <globals.h>

class GameBoard
{
	std::array<std::shared_ptr<BoardSquare>, BOARD_SIZE * BOARD_SIZE> board;
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

#endif // _GAME_BOARD_H
