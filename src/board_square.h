#include "game_piece.h"

class BoardSquare
{
	GamePiece& currentPiece;
public:
	BoardSquare();
	GamePiece& getPiece() const;
	void setPiece(GamePiece&);
};
