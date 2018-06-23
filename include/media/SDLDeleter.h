#ifndef _SDLDELETER_H
#define _SDLDELETER_H

#include <SDL2/SDL.h>

struct SDL_Deleter
{
	void operator()(SDL_Window*);
	void operator()(SDL_Renderer*);
	void operator()(SDL_Texture*);
};

#endif // _SDLDELETER_H
