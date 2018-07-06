#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

#include "common/global_decl.h"
#include "media/io.h"
#include "media/window.h"
#include "media/SDLDeleter.h"

int main()
{
	std::cout << "chicken shit\n";
	Window win("chicken shit lul");
	Io io;
	while(globals::running) {
		io.tick();
	}

	return 0;
}
