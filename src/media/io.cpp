#include <SDL2/SDL.h>
#include <stdexcept>
#include <iostream>

#include "media/io.h"
#include "common/globals.h"

void Io::tick()
{
	while (SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_KEYDOWN:
			executeMapEvent(event.key.keysym.sym, keyBindings);
			break;
		case SDL_QUIT:
			globals::running = false;
		}
	}
}

void Io::executeMapEvent(const Uint32& event, const FunctionMap& functMap)
{
	try {
		std::function<void()> exe = functMap.at(event);
	} catch(const std::out_of_range& e) {
		std::cerr << "ERROR [IO]: Event key " << event << " not mapped!\n";
	}
}
