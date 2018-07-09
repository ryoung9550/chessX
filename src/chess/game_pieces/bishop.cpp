#include "chess/game_pieces/bishop.h"
#include "chess/game_pieces/game_piece.h"

Bishop::Bishop(const Player& player) : GamePiece(player)
{
	setType(BISHOP);
}

BoardRep Bishop::validMove(const BoardRep& boardRep)
{

}
