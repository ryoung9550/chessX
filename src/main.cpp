#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

#include "media/io.h"
#include "media/window.h"
#include "media/SDLDeleter.h"

int main()
{
	bool running = true;
	std::cout << "chicken shit\n";
	Window win("chicken shit lul");
	Io io;
	io.setQuit([&running]() -> void {
		running = false;
	});

	io.setKeyBinding(SDLK_ESCAPE, [&running]() -> void {
		running = false;
	});

	while(running) {
		io.tick();
	}

	return 0;
}
