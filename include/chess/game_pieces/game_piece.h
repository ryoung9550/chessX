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
protected:
	void setType(const PieceType& type);
	void setPlayer(const Player& player);
public:
	GamePiece(const Player&, const PieceType&);
	PieceType getType();
	Player getPlayer();
};

#endif // _GAME_PIECE_H
