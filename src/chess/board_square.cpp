#include "game_board.h"
#include "game_pieces/game_piece.h"
#include "game_pieces/null_piece.h"
#include "../common/pos.h"
#include "../common/globals.h"

BoardSquare::BoardSquare(const Pos& pos) : pos(pos), piece(NullPiece()) {}

BoardSquare::BoardSquare(const Pos& pos, const GamePiece& piece) :
	pos(pos), piece(piece) {}

bool BoardSquare::hasPiece()
{
	if(piece.getType() != PieceType::EMPTY) {
		return	true;
	}
	return false;
}

GamePiece& BoardSquare::getPiece() { return piece; }

Pos BoardSquare::getPos() { return pos; }

void BoardSquare::clearPiece() { piece = NullPiece(); }
