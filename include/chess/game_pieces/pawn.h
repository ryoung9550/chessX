#ifndef _PAWN_H
#define _PAWN_H

#include "common/globals.h"
#include "chess/game_pieces/game_piece.h"

class Pawn : public GamePiece 
{
	bool moved;
public:
	Pawn(const Player&);
	bool hasMoved();
};

#endif // _PAWN_H
