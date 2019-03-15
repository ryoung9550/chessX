#ifndef _BOARD_SQUARE_H
#define _BOARD_SQUARE_H

#include "game_pieces/game_piece.h"
#include "../common/pos.h"

#include <memory>

class GameBoard; // forward declaration

class BoardSquare
{
	const Pos pos;
	GamePiece piece;
public:
	BoardSquare(const Pos& pos);
	BoardSquare(const Pos& pos, const GamePiece& piece);
	bool hasPiece();
	GamePiece& getPiece();
	Pos getPos();
	void clearPiece();
};

#endif // _BOARD_SQUARE_H
