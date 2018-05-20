#ifndef _BOARD_SQUARE_H
#define _BOARD_SQUARE_H

#include "game_pieces/game_piece.h"
#include "pos.h"
#include <memory>

class BoardSquare
{
	Pos squarePos;
	std::unique_ptr<GamePiece> currentPiece;
public:
	BoardSquare();
	BoardSquare(Pos& initPos);
	BoardSquare(Pos& initPos, GamePiece *const piece);
	void setPiece(std::unique_ptr<GamePiece>);
	std::unique_ptr<GamePiece> removePiece();
};

#endif // _BOARD_SQUARE_H
