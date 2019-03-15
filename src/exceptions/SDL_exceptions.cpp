#include "SDL_exceptions.h"

#include <SDL2/SDL.h>

const char* window_init_failed_exception::what() const throw()
{
	return SDL_GetError();
}
