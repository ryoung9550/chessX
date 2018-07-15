#ifndef _QUEEN_H
#define _QUEEN_H

#include "chess/game_pieces/game_piece.h"

class Queen : public GamePiece
{
public:
	Queen(const Player&);
};

#endif // _QUEEN_H
