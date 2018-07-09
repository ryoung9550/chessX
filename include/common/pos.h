#ifndef _POS_H
#define _POS_H

#include <cstdio>

// Position of board from file and rank from 0-7
struct Pos
{
	// File is the virtical orientation while
	// rank is the horizontal orientation
	size_t file, rank;

	static size_t posToIndex(Pos pos);
	static Pos indexToPos(size_t);
};

#endif // _POS_H
