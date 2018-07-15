#ifndef _GLOBALS_H
#define _GLOBALS_H

#include <cstdio>
#include <array>

namespace globals {
	const size_t BOARD_SIZE = 8;
	const size_t DEFAULT_WIN_H = 480;
	const size_t DEFAULT_WIN_W = 720;
}

typedef std::array<size_t, globals::BOARD_SIZE * globals::BOARD_SIZE> BoardRep; // Board Representation

enum Player
{
	WHITE_PLAYER,
	BLACK_PLAYER,
	NOT_A_PLAYER
};

enum MoveType
{
	VALID_MOVE,
	INVALID_MOVE
};

enum PieceType
{
	PAWN,
	ROOK,
	KNIGHT,
	BISHOP,
	QUEEN,
	KING,
	EMPTY
};

/*
enum PieceDetail
{
	W_ROOK,
	W_KNIGHT,
	W_BISHOP,
	W_QUEEN,
	W_KING,
	W_PAWN,
	B_ROOK,
	B_KNIGHT,
	B_BISHOP,
	B_QUEEN,
	B_KING,
	B_PAWN,
	EMPTY
};
*/


#endif // _GLOBALS_H
