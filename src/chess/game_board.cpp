#include "chess/game_board.h"
#include "chess/board_square.h"
#include "common/globals.h"
#include "common/pos.h"
#include "chess/game_pieces/pawn.h"
#include "chess/game_pieces/rook.h"
#include "chess/game_pieces/knight.h"
#include "chess/game_pieces/bishop.h"
#include "chess/game_pieces/queen.h"
#include "chess/game_pieces/king.h"
#include "chess/game_pieces/null_piece.h"

#include <memory>
#include <array>

/*
 * Default chess board:
 *
 *   a b c d e f g h
 * 1
 * 2
 * 3
 * 4
 * 5
 * 6
 * 7
 * 8
 *
 * the 0th index begins at A1 then the 1st
 * is B1 and snakes until the 63rd index
 * at position H8
 */

#define WHITE_ROOK_1 0
#define WHITE_KNIGHT_1 1
#define WHITE_BISHOP_1 2
#define WHITE_QUEEN 3
#define WHITE_KING 4
#define WHITE_BISHOP_2 5
#define WHITE_KNIGHT_2 6
#define WHITE_ROOK_2 7
#define W_PAWN_1 8
#define W_PAWN_2 9
#define W_PAWN_3 10
#define W_PAWN_4 11
#define W_PAWN_5 12
#define W_PAWN_6 13
#define W_PAWN_7 14
#define W_PAWN_8 15

#define BLACK_ROOK_1 63
#define BLACK_KNIGHT_1 62
#define BLACK_BISHOP_1 61
#define BLACK_KING 60
#define BLACK_QUEEN 59
#define BLACK_BISHOP_2 58
#define BLACK_KNIGHT_2 57
#define BLACK_ROOK_2 56
#define B_PAWN_1 55
#define B_PAWN_2 54
#define B_PAWN_3 53
#define B_PAWN_4 52
#define B_PAWN_5 51
#define B_PAWN_6 50
#define B_PAWN_7 49
#define B_PAWN_8 48

#define bs BoardSquare

GameBoard::GameBoard() : gameSquares({bs(0), bs(1), bs(2), bs(3), bs(4),
	bs(5), bs(6), bs(7), bs(8), bs(9), bs(10), bs(11), bs(12), bs(13),
	bs(14), bs(15), bs(16), bs(17), bs(18), bs(19), bs(20), bs(21), bs(22),
	bs(23), bs(24), bs(25), bs(26), bs(27), bs(28), bs(29), bs(30), bs(31),
	bs(32), bs(33), bs(34), bs(35), bs(36), bs(37), bs(38), bs(39), bs(40),
	bs(41), bs(42), bs(43), bs(44), bs(45), bs(46), bs(47), bs(48), bs(49),
	bs(50), bs(51), bs(52), bs(53), bs(54), bs(55), bs(56), bs(57), bs(58),
	bs(59), bs(60), bs(61), bs(62), bs(63)})
{
	// Init Board
	for(size_t i = 0; i < globals::BOARD_SIZE * globals::BOARD_SIZE; ++i) {
		gameSquares[i].clearPiece();
	}


	// Setup white pawns

	gameSquares[W_PAWN_1].getPiece() = Pawn(Player::WHITE_PLAYER);
	gameSquares[W_PAWN_2].getPiece() = Pawn(Player::WHITE_PLAYER);
	gameSquares[W_PAWN_3].getPiece() = Pawn(Player::WHITE_PLAYER);
	gameSquares[W_PAWN_4].getPiece() = Pawn(Player::WHITE_PLAYER);
	gameSquares[W_PAWN_5].getPiece() = Pawn(Player::WHITE_PLAYER);
	gameSquares[W_PAWN_6].getPiece() = Pawn(Player::WHITE_PLAYER);
	gameSquares[W_PAWN_7].getPiece() = Pawn(Player::WHITE_PLAYER);
	gameSquares[W_PAWN_8].getPiece() = Pawn(Player::WHITE_PLAYER);

	// Setup main white pieces
	gameSquares[WHITE_ROOK_1].getPiece() = Rook(Player::WHITE_PLAYER);
	gameSquares[WHITE_ROOK_2].getPiece() = Rook(Player::WHITE_PLAYER);

	gameSquares[WHITE_KNIGHT_1].getPiece() = Knight(Player::WHITE_PLAYER);
	gameSquares[WHITE_KNIGHT_2].getPiece() = Knight(Player::WHITE_PLAYER);

	gameSquares[WHITE_BISHOP_1].getPiece() = Bishop(Player::WHITE_PLAYER);
	gameSquares[WHITE_BISHOP_2].getPiece() = Bishop(Player::WHITE_PLAYER);

	gameSquares[WHITE_QUEEN].getPiece() = Queen(Player::WHITE_PLAYER);
	gameSquares[WHITE_KING].getPiece() = King(Player::WHITE_PLAYER);

	// Setup black pawns
	gameSquares[B_PAWN_1].getPiece() = Pawn(Player::BLACK_PLAYER);
	gameSquares[B_PAWN_2].getPiece() = Pawn(Player::BLACK_PLAYER);
	gameSquares[B_PAWN_3].getPiece() = Pawn(Player::BLACK_PLAYER);
	gameSquares[B_PAWN_4].getPiece() = Pawn(Player::BLACK_PLAYER);
	gameSquares[B_PAWN_5].getPiece() = Pawn(Player::BLACK_PLAYER);
	gameSquares[B_PAWN_6].getPiece() = Pawn(Player::BLACK_PLAYER);
	gameSquares[B_PAWN_7].getPiece() = Pawn(Player::BLACK_PLAYER);
	gameSquares[B_PAWN_8].getPiece() = Pawn(Player::BLACK_PLAYER);

	// Setup main black pieces
	gameSquares[BLACK_ROOK_1].getPiece() = Rook(Player::BLACK_PLAYER);
	gameSquares[BLACK_ROOK_2].getPiece() = Rook(Player::BLACK_PLAYER);

	gameSquares[BLACK_KNIGHT_1].getPiece() = Knight(Player::BLACK_PLAYER);
	gameSquares[BLACK_KNIGHT_2].getPiece() = Knight(Player::BLACK_PLAYER);

	gameSquares[BLACK_BISHOP_1].getPiece() = Bishop(Player::BLACK_PLAYER);
	gameSquares[BLACK_BISHOP_2].getPiece() = Bishop(Player::BLACK_PLAYER);

	gameSquares[BLACK_QUEEN].getPiece() = Queen(Player::BLACK_PLAYER);
	gameSquares[BLACK_KING].getPiece() = King(Player::BLACK_PLAYER);
}

BoardSquare& GameBoard::getSquare(const Pos& pos)
{
	return gameSquares[Pos::posToIndex(pos)];
}

BoardSquare& GameBoard::getSquare(const size_t& rank, const size_t& file)
{
	return gameSquares[rank + (file * globals::BOARD_SIZE)];
}

void GameBoard::movePiece(const Pos& src, const Pos& dest)
{
	if(getSquare(dest).hasPiece()) {
		capturedPieces.push_back(getSquare(dest).getPiece());
	}
	getSquare(dest).getPiece() = getSquare(src).getPiece();
	getSquare(src).getPiece() = NullPiece();
}

