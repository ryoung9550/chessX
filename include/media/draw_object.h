#ifndef _DRAWOBJECT_H
#define _DRAWOBJECT_H

#include <SDL2/SDL.h>
#include <memory>

#include "media/texture.h"

class DrawObject
{
	std::shared_ptr<Texture> refTexture;
	SDL_Rect drawArea;
public:
	DrawObject();
	void setTexture(std::shared_ptr<SDL_Texture>);
	SDL_Rect& getDrawArea();
	void setDrawArea(const SDL_Rect&);
};

#endif // _DRAWOBJECT_H
