#include "media/window.h"
#include "common/globals.h"
#include "exceptions/SDL_exceptions.h"

#include <vector>
#include <string>
#include <SDL2/SDL.h>

Window::Window(std::string title) :
	window(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, globals::DEFAULT_WIN_H, 
		globals::DEFAULT_WIN_W, 0)),
	renderer(SDL_CreateRenderer(window.get(), -1, 0))
{
	if (this->window.get() == nullptr) {
		throw new window_init_failed_exception(SDL_GetError());
	}
}
