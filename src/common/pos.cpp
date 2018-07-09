#include "common/pos.h"
#include "common/globals.h"

#define POS_OUT_OF_BOUNDS ((SIZE_T_MAX)(~0ul))

size_t Pos::posToIndex(Pos pos)
{
	size_t index = pos.file;
	index += pos.rank * globals::BOARD_SIZE;
	return index;
}

Pos Pos::indexToPos(size_t index)
{
	return Pos{/*file*/ index%globals::BOARD_SIZE, /*file*/ index/globals::BOARD_SIZE};
}
