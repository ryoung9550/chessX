#include "common/pos.h"
#include "common/globals.h"

size_t Pos::posToIndex(Pos pos)
{
	size_t index = pos.rank;
	index += pos.file * globals::BOARD_SIZE;
	return index;
}

Pos Pos::indexToPos(size_t index)
{
	return Pos{/*rank*/ index%globals::BOARD_SIZE, /*file*/ index/globals::BOARD_SIZE};
}
