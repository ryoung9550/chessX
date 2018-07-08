#ifndef _BOARD_SQUARE_H
#define _BOARD_SQUARE_H

#include "chess/game_pieces/game_piece.h"
#include "common/pos.h"

#include <memory>

class GameBoard; // forward declaration

class BoardSquare
{
	GameBoard& owner;
	const Pos pos;
	std::unique_ptr<GamePiece> currentPiece;
public:
	BoardSquare(GameBoard&, const Pos& pos);
	BoardSquare(GameBoard&, const Pos& pos, GamePiece *piece);
	std::unique_ptr<GamePiece> removePiece();
	bool hasPiece();
	size_t getPieceType();
	Pos getPos();
	void setPiece(std::unique_ptr<GamePiece>);
};

#endif // _BOARD_SQUARE_H
