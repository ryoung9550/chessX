#pragma once

#include "game_pieces/game_piece.h"
#include "component/game_board.h"
#include "common/pos.h"

#include <memory>

class BoardSquare
{
	GameBoard& owner;
	std::unique_ptr<GamePiece> currentPiece;
public:
	BoardSquare(GameBoard&);
	BoardSquare(GameBoard&, GamePiece *const piece);
	std::unique_ptr<GamePiece> removePiece();
	void setPiece(std::unique_ptr<GamePiece>);
};

