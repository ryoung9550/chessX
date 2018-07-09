#ifndef _BISHOP_H
#define _BISHOP_H

#include "common/globals.h"
#include "chess/game_pieces/game_piece.h"

class Bishop : public GamePiece
{
public:
	Bishop(const Player& player);
	virtual BoardRep validMove(const BoardRep& boardRep) override;
};

#endif // _BISHOP_H
