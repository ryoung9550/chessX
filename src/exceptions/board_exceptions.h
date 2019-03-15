#ifndef _BOARD_EXCEPTIONS
#define _BOARD_EXCEPTIONS

#include <string>
#include <exception>

class square_has_piece_exception : public std::exception 
{
	const char* what() const throw();
};

#endif // _BOARD_EXCEPTIONS
