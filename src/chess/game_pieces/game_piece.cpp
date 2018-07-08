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
