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
	SDL_Rect pos; // Dimensions and position of View
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
	/*
	 * Renders all Draw Object which are visible to the View in
	 * order of farthest objects to nearest.
	 */
	void draw();

	/*
	 * Loads a PNG or JPG image from the filepath provided. Creates
	 * the texture object then adds it to the textures Map.
	 * @param std::string - Name used to access Texture from getTexture()
	 * @param std::string - Path of PNG or JPG image
	 *
	 * @see getTexture()
	 * @throws logic_error - If Name already exists in the Map
	 */
	void loadTexture(std::string, std::string);

	/*
	 * Removes the Texture reference from the Map. The Texture
	 * will remain to exist until all references from the Draw
	 * Objects have also been cleaned up.
	 * @param std::string - Name of texture to be removed from the Map
	 */
	void unloadTexture(std::string);

	/*
	 * Gets a reference to a texture with the Name used to add
	 * the texture previously from loading it.
	 * @param std::string - Name of Texture indexed into the Map
	 *
	 * @throws out_of_range - If texture is not indexed
	 */
	std::shared_ptr<SDL_Texture> getTexture(std::string);
};

#endif // _VIEW_H
