#include "exceptions/board_exceptions.h"
#include "game_pieces/game_piece.h"
#include "component/board_square.h"
#include "component/game_board.h"
#include "common/pos.h"

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
		throw new square_has_piece_exception;
	}
}

