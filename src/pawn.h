#include "game_piece.h"

class Pawn : public GamePiece 
{
	bool notMoved;
	bool validMove(const Pos& dest);
public:
	void move(const Pos& dest);
};
