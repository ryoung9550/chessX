#ifndef _PAWN_H
#define _PAWN_H

#include <game_pieces/game_piece.h>

class Pawn : public GamePiece 
{
	bool notMoved;
	bool validMove(const Pos& dest);
public:
	void move(const Pos& dest);
};

#endif // _PAWN_H
