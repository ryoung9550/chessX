#include "exceptions/board_exceptions.h"
#include "game_pieces/game_piece.h"
#include "component/board_square.h"
#include "component/game_board.h"
#include "common/pos.h"

#include <memory>

BoardSquare::BoardSquare(GameBoard& parrent) : owner(parrent), currentPiece(nullptr) {}

BoardSquare::BoardSquare(GameBoard& parrent, GamePiece *piece) : owner(parrent), currentPiece(piece) {}

std::unique_ptr<GamePiece> BoardSquare::removePiece()
{
	return std::move(currentPiece);
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

bool BoardSquare::hasPiece()
{
	return (currentPiece.get() != nullptr);
}
