#ifndef _GAME_PIECE_H
#define _GAME_PIECE_H

#include <globals.h>
#include <pos.h>

class GamePiece 
{
	Player player;
protected:
	virtual bool validMove(const Pos& dest);
public:
	GamePiece(const Player&);
	/*
	 * @brief - moves piece to destination
	 */
	void move(const Pos& dest);	
	void setPos(const Pos& pos);
	Pos getPos() const;
};

#endif // _GAME_PIECE_H
