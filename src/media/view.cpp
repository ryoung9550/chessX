#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "view.h"
#include "../common/SDLInit.h"

void View::draw()
{
	
}

void View::loadTexture(std::string /*regName*/, std::string path)
{
	SDL_Surface* imgSurf = IMG_Load(path.c_str());
}
