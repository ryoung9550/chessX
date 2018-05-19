#include "board_square.h"


BoardSquare::BoardSquare()
{
	squarePos = { 0, 0 };
	currentPiece = std::unique_ptr<GamePiece>(nullptr);
}

BoardSquare::BoardSquare(Pos& initPos)
{
	squarePos = initPos;
	currentPiece = std::unique_ptr<GamePiece>(nullptr);
}

BoardSquare::BoardSquare(Pos& initPos, GamePiece *const piece)
{
	squarePos = initPos;
	currentPiece = std::unique_ptr<GamePiece>(piece);
}

std::unique_ptr<GamePiece> BoardSquare::removePiece()
{
	std::unique_ptr<GamePiece> uptr = std::unique_ptr<GamePiece>(std::move(currentPiece));
	return uptr;
}

void BoardSquare::setPiece(std::unique_ptr<GamePiece> srcPtr)
{
	if (currentPiece.get() == nullptr) {
		currentPiece.reset();
		currentPiece = (std::move(srcPtr));
	} else {
		//TODO: Add SquareHasPiece Exception
	}
}
