#ifndef _GAME_BOARD_H
#define _GAME_BOARD_H
#pragma once

#include "chess/board_square.h"
#include "common/globals.h"

#include <array>
#include <memory>
#include <vector>

class GameBoard
{
	std::array<BoardSquare, globals::BOARD_SIZE * globals::BOARD_SIZE> gameSquares;
	std::vector<GamePiece> capturedPieces{};
	int getPosOffset(const Pos&);
public:
	/*
	 * @brief - Create new gameboard with gamesquare and all game pieces
	 */
	GameBoard();

	/*
	 * @brief - Return reference to square
	 */
	BoardSquare& getSquare(const Pos& pos);
	BoardSquare& getSquare(const size_t& rank, const size_t& file);
	void movePiece(const Pos&, const Pos&);
};

#endif // _GAME_BOARD_H
