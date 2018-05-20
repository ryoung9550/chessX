#include "game_piece.h"
#include <memory>
#include "pos.h"

class BoardSquare
{
	Pos squarePos;
	std::unique_ptr<GamePiece> currentPiece;
public:
	BoardSquare();
	BoardSquare(Pos& initPos);
	BoardSquare(Pos& initPos, GamePiece *const piece);
	std::unique_ptr<GamePiece> removePiece();
	void setPiece(std::unique_ptr<GamePiece>);
};
