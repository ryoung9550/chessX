#include "media/draw_object.h"

#include <vector>
#include <string>
#include <memory>
#include <SDL2/SDL.h>

struct SDL_Deleter
{
	SDL_Deleter(SDL_Window*);
	SDL_Deleter(SDL_Renderer*);
};

class Window
{
	std::unique_ptr<SDL_Window> window;
	std::unique_ptr<SDL_Renderer> renderer;
	std::vector<DrawObject> renderList;
public:
	Window(std::string title);
	~Window();
};
