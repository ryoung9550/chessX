#include "game_piece.h"
#include "pos.h"

class BoardSquare
{
	Pos squarePos;
	GamePiece& currentPiece;
public:
	BoardSquare();
	BoardSquare(const Pos& initPos);
	BoardSquare(const Pos& initPos, GamePiece& piece);
	GamePiece& getPiece();
	void setPiece(GamePiece&);
};
