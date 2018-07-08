#ifndef _GAME_PIECE_H
#define _GAME_PIECE_H

#include "common/globals.h"
#include "common/pos.h"

#include <memory>

class BoardSquare;

class GamePiece 
{
	Player player;
	size_t type;
	std::shared_ptr<BoardSquare> currentSquare;
public:
	GamePiece(const Player&);

	/// Returns a BoardRep with all values of which
	/// squares are valid moves indicated with the enum
	/// VALID_MOVE and invalid moves marked with the enum
	/// INVALID_MOVE.
	virtual BoardRep validMove(BoardRep boardRep) = 0;

	size_t getType();
	Pos getPosition();
	void setCurrentSquare(std::shared_ptr<BoardSquare> boardSquare);
};

#endif // _GAME_PIECE_H
