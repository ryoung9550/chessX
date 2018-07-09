#ifndef _GAME_PIECE_H
#define _GAME_PIECE_H

#include "common/globals.h"
#include "common/pos.h"

#include <memory>

class BoardSquare;

class GamePiece 
{
	Player player;
	PieceType type;
	std::shared_ptr<BoardSquare> currentSquare;
protected:
	void setType(const PieceType& type);
public:
	GamePiece(const Player&);

	/// Returns a BoardRep with all values of which
	/// squares are valid moves indicated with the enum
	/// VALID_MOVE and invalid moves marked with the enum
	/// INVALID_MOVE.
	virtual BoardRep validMove(const BoardRep& boardRep) = 0;

	size_t getType();
	Pos getPosition();
	void setCurrentSquare(std::shared_ptr<BoardSquare> boardSquare);
};

bool isPosInBounds(Pos pos);
void initializeBoardRep(BoardRep& boardRep);
Player getPlayerFromBoard(const BoardRep& boardRep, const Pos& pos);

#endif // _GAME_PIECE_H
