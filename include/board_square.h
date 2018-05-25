#ifndef _BOARD_SQUARE_H
#define _BOARD_SQUARE_H

#include <game_pieces/game_piece.h>
#include <game_board.h>
#include <pos.h>
#include <memory>

class BoardSquare
{
	GameBoard& owner;
	std::unique_ptr<GamePiece> currentPiece;
public:
	BoardSquare(GameBoard&);
	BoardSquare(GameBoard&, GamePiece *const piece);
	std::unique_ptr<GamePiece> removePiece();
	void setPiece(std::unique_ptr<GamePiece>);
};

#endif // _BOARD_SQUARE_H
