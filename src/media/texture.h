#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <memory>
#include <SDL2/SDL.h>

#include "SDLDeleter.h"

class Texture
{
	std::shared_ptr<SDL_Surface> texture;
	SDL_Rect size;
public:
	Texture(std::string imgFilepath);
	const SDL_Rect& getSize() const;
	std::shared_ptr<SDL_Surface> getTexture();
};

#endif // _TEXTURE_H
