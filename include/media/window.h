#include "media/draw_object.h"

#include <vector>
#include <string>
#include <memory>
#include <SDL2/SDL.h>

struct SDL_Deleter
{
	void operator()(SDL_Window*);
	void operator()(SDL_Renderer*);
};

class Window
{
	std::unique_ptr<SDL_Window, SDL_Deleter> window;
	std::unique_ptr<SDL_Renderer, SDL_Deleter> renderer;
	std::vector<DrawObject> renderList;
public:
	Window(std::string title);
	~Window();
};
