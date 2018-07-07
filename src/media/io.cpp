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
			executeQuit();
		}
	}
}

void Io::executeMapEvent(const size_t& event, const FunctionMap& functMap)
{
	try {
		std::function<void()> exe = functMap.at(event);
		exe();
		std::cout << "Executed function for key " << event << '\n';
	} catch(const std::out_of_range& e) {
		std::cerr << "ERROR [IO]: Event key " << event << " not mapped!\n";
	}
}

void Io::setKeyBinding(const size_t& keyCode, const std::function<void()>& funct)
{
	this->keyBindings.insert(std::pair<size_t, std::function<void()>>(keyCode, funct));
}

void Io::setQuit(const std::function<void()>& quitFunct)
{
	this->quitFunct = quitFunct;
}

void Io::executeQuit()
{
	quitFunct();
}
