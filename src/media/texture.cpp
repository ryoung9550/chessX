#include <memory>
#include <SDL2/SDL.h>

#include "media/texture.h"

Texture::Texture(std::unique_ptr<SDL_Texture> texture, const SDL_Rect& size)
{
	this->texture = std::move(texture);
	this->size = size;
}

const SDL_Rect& Texture::getSize()
{
	return size;
}
