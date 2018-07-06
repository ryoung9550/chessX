#ifndef _BOARD_SQUARE_H
#define _BOARD_SQUARE_H

#include "chess/game_pieces/game_piece.h"
#include "common/pos.h"

#include <memory>

class GameBoard; // forward declaration

class BoardSquare
{
	GameBoard& owner;
	std::unique_ptr<GamePiece> currentPiece;
public:
	BoardSquare(GameBoard&);
	BoardSquare(GameBoard&, GamePiece *piece);
	std::unique_ptr<GamePiece> removePiece();
	bool hasPiece();
	size_t getPieceType();
	void setPiece(std::unique_ptr<GamePiece>);
};

#endif // _BOARD_SQUARE_H
