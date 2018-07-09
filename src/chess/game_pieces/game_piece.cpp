#include <memory>

#include "chess/game_pieces/game_piece.h"
#include "chess/board_square.h"
#include "common/globals.h"

GamePiece::GamePiece(const Player& p)
{
	player = p;
}

size_t GamePiece::getType()
{
	return this->type;
}

void GamePiece::setCurrentSquare(std::shared_ptr<BoardSquare> boardSquare)
{
	this->currentSquare = boardSquare;
}

Pos GamePiece::getPosition()
{
	return currentSquare->getPos();
}

void GamePiece::setType(const PieceType& type)
{
	this->type = type;
}

bool isPosInBounds(Pos pos)
{
	if (pos.file < globals::BOARD_SIZE && pos.rank < globals::BOARD_SIZE) {
		return true;
	}
	return false;
}

void initializeBoardRep(BoardRep& boardRep)
{
	for(size_t i = 0; i < boardRep.size(); ++i) {
		boardRep[i] = INVALID_MOVE;
	}
}

Player getPlayerFromBoard(const BoardRep& boardRep, const Pos& pos)
{
	size_t piece = boardRep[Pos::posToIndex(pos)];
	if(piece == EMPTY) {
		return NOT_A_PLAYER;
	}

	if(piece >= W_ROOK && piece <= W_PAWN) {
		return WHITE_PLAYER;
	}
	
	return BLACK_PLAYER;
}
