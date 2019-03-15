#include "../../common/globals.h"
#include "../../common/pos.h"
#include "../game_pieces/knight.h"

static const size_t POSSIBLE_MOVES = 2;

Knight::Knight(const Player& player) : GamePiece(player)
{
	setType(KNIGHT);
}

BoardRep Knight::validMove(const BoardRep& boardRep)
{
	BoardRep retBoard;
	initializeBoardRep(retBoard);
	Pos currentPos = this->getPosition();
	Pos possibleMoves[POSSIBLE_MOVES] =
		{ Pos{3, 2}, Pos{2, 3} };
	for (size_t i = 0; i < 4; ++i) { // rotate the moves. Total of 8 moves
		Pos pos1, pos2;
		switch(i) {
		case 0:
			pos1 = Pos{possibleMoves[0].file + currentPos.file,
				possibleMoves[0].rank + currentPos.rank};
			pos2 = Pos{possibleMoves[1].file + currentPos.file,
				possibleMoves[1].rank + currentPos.rank};
			break;
		case 1:
			pos1 = Pos{possibleMoves[0].file - currentPos.file,
				possibleMoves[0].rank + currentPos.rank};
			pos2 = Pos{possibleMoves[1].file - currentPos.file,
				possibleMoves[1].rank + currentPos.rank};
			break;
		case 2:
			pos1 = Pos{possibleMoves[0].file + currentPos.file,
				possibleMoves[0].rank - currentPos.rank};
			pos2 = Pos{possibleMoves[1].file + currentPos.file,
				possibleMoves[1].rank - currentPos.rank};
			break;
		case 3:
			pos1 = Pos{possibleMoves[0].file - currentPos.file,
				possibleMoves[0].rank - currentPos.rank};
			pos2 = Pos{possibleMoves[1].file - currentPos.file,
				possibleMoves[1].rank - currentPos.rank};
			break;
		}
		if(isPosInBounds(pos1)) {
			if(boardRep[Pos::posToIndex(pos1)] == EMPTY) { // Is position empty?
				retBoard[Pos::posToIndex(pos1)] = VALID_MOVE;
			} else {
				Player player = getPlayerFromBoard(boardRep, currentPos);
				if(player == WHITE_PLAYER && getPlayerFromBoard(boardRep, pos1) == BLACK_PLAYER) {
					retBoard[Pos::posToIndex(pos1)] = VALID_MOVE;
				} else if(player == BLACK_PLAYER && getPlayerFromBoard(boardRep, pos1) == WHITE_PLAYER) {
					retBoard[Pos::posToIndex(pos1)] = VALID_MOVE;
				}
			}
		}
	}

	return retBoard;
}

