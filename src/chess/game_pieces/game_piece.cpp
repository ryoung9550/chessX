#include "chess/game_pieces/game_piece.h"
#include "common/globals.h"

bool GamePiece::validMove(const Pos& /*dest*/)
{
	return false;
}

GamePiece::GamePiece(const Player& p)
{
	player = p;
}

size_t GamePiece::getType()
{
	return this->type;
}
