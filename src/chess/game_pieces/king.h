#ifndef _KING_H
#define _KING_H

#include "../../common/globals.h"
#include "../game_pieces/game_piece.h"

class King : public GamePiece
{
public:
	King(const Player&);
};

#endif // _KING_H
