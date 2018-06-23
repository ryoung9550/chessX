#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <memory>
#include <SDL2/SDL.h>

class Texture
{
	std::unique_ptr<SDL_Texture> texture;
	SDL_Rect size;
public:
	Texture(std::unique_ptr<SDL_Texture>, const SDL_Rect&);
	const SDL_Rect& getSize();
};

#endif // _TEXTURE_H
