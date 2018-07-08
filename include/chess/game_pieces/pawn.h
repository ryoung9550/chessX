#ifndef _PAWN_H
#define _PAWN_H

#include "chess/game_pieces/game_piece.h"

class Pawn : public GamePiece 
{
	bool notMoved;
public:
	virtual BoardRep validMove(BoardRep boardRep) override;
};

#endif // _PAWN_H
