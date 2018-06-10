#ifndef _SDL_EXCEPTIONS_H
#define _SDL_EXCEPTIONS_H

#include <exception>

class window_init_failed_exception : public std::exception
{
	const char* what() const throw();
};

#endif // _SDL_EXCEPTIONS_H
