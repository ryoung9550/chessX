#include "window.h"
#include "../common/globals.h"
#include "../common/SDLInit.h"
#include "../exceptions/SDL_exceptions.h"

#include <vector>
#include <string>
#include <memory>
#include <SDL2/SDL.h>


Window::Window(std::string title) : window(
		SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, globals::DEFAULT_WIN_W, 
		globals::DEFAULT_WIN_H, 0))
{
	if (this->window.get() == nullptr) {
		
		throw new window_init_failed_exception();
	}
}

Window::~Window() {}
