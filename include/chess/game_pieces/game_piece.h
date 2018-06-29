#ifndef _GAME_PIECE_H
#define _GAME_PIECE_H

#include "common/globals.h"
#include "common/pos.h"

#include <memory>

class BoardSquare;

class GamePiece 
{
	Player player;
public:
	GamePiece(const Player&);
	virtual bool validMove(const Pos& dest);
};

#endif // _GAME_PIECE_H
