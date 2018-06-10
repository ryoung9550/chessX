#include "media/draw_object.h"

#include <vector>
#include <string>
#include <memory>
#include <SDL2/SDL.h>

class Window
{
	std::unique_ptr<SDL_Window> window;
	std::unique_ptr<SDL_Renderer> renderer;
	std::vector<DrawObject> renderList;
public:
	Window(std::string title);
};
