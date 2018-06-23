#ifndef _VIEW_H
#define _VIEW_H

#include <SDL2/SDL.h>
#include <memory>
#include <vector>
#include <unordered_map>

#include "media/SDLDeleter.h"
#include "media/draw_object.h"

class View
{
	SDL_Rect pos;
	std::unique_ptr<SDL_Renderer, SDL_Deleter> renderer;
	std::vector<DrawObject> renderList;
	std::unordered_map<char*, std::shared_ptr<SDL_Texture>> textures;

	/*
	 * Takes a DrawObject and checks to see if it is in view
	 * to render only the viewable DrawObjects
	 *
	 * @param drawable - Object to check for if it's in view
	 * @return - Return true if in view, else false
	 */
	bool inView(DrawObject);
public:
	void draw();
	void loadTexture(std::string);
	void unloadTexture(std::string);
	std::shared_ptr<SDL_Texture> getTexture(std::string);
};

#endif // _VIEW_H
