#ifndef _WINDOW_H
#define _WINDOW_H

#include <vector>
#include <string>
#include <memory>
#include <SDL2/SDL.h>

#include "media/view.h"
#include "media/SDLDeleter.h"
#include "media/draw_object.h"

class Window
{
	std::unique_ptr<SDL_Window, SDL_Deleter> window;
public:
	Window(std::string title);
	~Window();
	View& getView(int, Uint32);
};

#endif // _WINDOW_H
