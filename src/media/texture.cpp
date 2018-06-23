#include <memory>
#include <SDL2/SDL.h>

#include "media/texture.h"
#include "media/SDLDeleter.h"

Texture::Texture(std::unique_ptr<SDL_Texture, SDL_Deleter> texture, const SDL_Rect& size)
{
	this->texture = std::move(texture);
	this->size = size;
}

const SDL_Rect& Texture::getSize()
{
	return size;
}
