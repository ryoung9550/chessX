#include "board_exceptions.h"

const char* square_has_piece_exception::what() const throw()
{
	return "This square is filled by another piece.";
}
