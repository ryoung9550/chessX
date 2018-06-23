#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <memory>
#include <SDL2/SDL.h>

#include "media/SDLDeleter.h"

class Texture
{
	std::unique_ptr<SDL_Texture, SDL_Deleter> texture;
	SDL_Rect size;
public:
	Texture();
	Texture(std::unique_ptr<SDL_Texture, SDL_Deleter>, const SDL_Rect&);
	const SDL_Rect& getSize();
};

#endif // _TEXTURE_H
