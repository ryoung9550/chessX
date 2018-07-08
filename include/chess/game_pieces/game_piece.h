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
public:
	GamePiece(const Player&);
	virtual bool validMove(const Pos& dest, std::array<size_t, 64> boardRep);
	size_t getType();
};

#endif // _GAME_PIECE_H
