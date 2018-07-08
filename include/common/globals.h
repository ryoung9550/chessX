#ifndef _GLOBALS_H
#define _GLOBALS_H

#include <cstdio>
#include <array>

typedef int Player;
typedef std::array<size_t, 64> BoardRep; // Board Representation

enum 
{
	WHITE_PLAYER,
	BLACK_PLAYER
};

enum
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

namespace globals {
	const size_t BOARD_SIZE = 8;
	const size_t DEFAULT_WIN_H = 480;
	const size_t DEFAULT_WIN_W = 720;
}

#endif // _GLOBALS_H
