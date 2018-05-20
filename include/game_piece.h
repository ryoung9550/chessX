#include "globals.h"
#include "pos.h" 

class GamePiece 
{
	Pos position;
protected:
	virtual bool validMove(const Pos& dest);
public:
	/*
	 * @brief - moves piece to destination
	 */
	virtual void move(const Pos& dest);	
	void setPos(const Pos& pos);
	Pos getPos() const;
};

