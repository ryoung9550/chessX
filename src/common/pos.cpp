#include "pos.h"
#include "globals.h"

#define POS_OUT_OF_BOUNDS ((SIZE_T_MAX)(~0ul))

Pos::Pos(const size_t& index) : file(index % globals::BOARD_SIZE),
	rank(index / globals::BOARD_SIZE) {}

Pos::Pos(const size_t& file, const size_t& rank) : file(file), rank(rank) {}

size_t Pos::posToIndex(Pos pos)
{
	size_t index = pos.file;
	index += pos.rank * globals::BOARD_SIZE;
	return index;
}

Pos Pos::indexToPos(size_t index)
{
	return Pos(/*file*/ index%globals::BOARD_SIZE, /*file*/ index/globals::BOARD_SIZE);
}
