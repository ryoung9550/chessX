#include <game_pieces/game_piece.h>
#include <board_square.h>
#include <game_board.h>
#include <pos.h>

#include <memory>

BoardSquare::BoardSquare(GameBoard& parrent) : owner(parrent), currentPiece(nullptr) {}

BoardSquare::BoardSquare(GameBoard& parrent, GamePiece *const piece) : owner(parrent), currentPiece(piece) {}

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

