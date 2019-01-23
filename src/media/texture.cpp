#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "media/texture.h"
#include "media/SDLDeleter.h"

Texture::Texture(std::string imgFilepath)
{
	 this->texture = std::shared_ptr<SDL_Surface>(IMG_Load(imgFilepath.c_str()));
}

const SDL_Rect& Texture::getSize() const
{
	return size;
}
