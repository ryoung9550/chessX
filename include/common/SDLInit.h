#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

class {
	bool init = false;
	bool timer = false;
	bool audio = false;
	bool video = false;
	bool joystick = false;
	bool haptic = false;
	bool gamecontroller = false;
	bool events = false;
	bool noparachute = false;
public:
	bool isRunning(Uint32 flag) const 
	{
		switch(flag) {
			case SDL_INIT_TIMER: return timer; break;
			case SDL_INIT_AUDIO: return audio; break;
			case SDL_INIT_VIDEO: return video; break;
			case SDL_INIT_JOYSTICK: return joystick; break;
			case SDL_INIT_HAPTIC: return haptic; break;
			case SDL_INIT_GAMECONTROLLER: return gamecontroller; break;
			case SDL_INIT_EVENTS: return events; break;
			case SDL_INIT_NOPARACHUTE: return noparachute; break;
		}
		return false;
	}

	/*
	 * Toggles service variable idicating whether a service is
	 * enabled or disabled.
	 * @param flag - SDL Define of the service to be toggled
	 */
	void toggleService(const Uint32& flag) 
	{
		switch(flag) {
			case SDL_INIT_TIMER: timer = !timer;  break;
			case SDL_INIT_AUDIO: audio = !audio; break;
			case SDL_INIT_VIDEO: video = !video; break;
			case SDL_INIT_JOYSTICK: joystick = !joystick; break;
			case SDL_INIT_HAPTIC: haptic = !haptic; break;
			case SDL_INIT_GAMECONTROLLER: gamecontroller = !gamecontroller; break;
			case SDL_INIT_EVENTS: events = !events; break;
			case SDL_INIT_NOPARACHUTE: noparachute = !noparachute; break;
		}
	}

	void start(const Uint32& flag) 
	{
		if (!init) {
			init = true;
			SDL_Init(flag);
			if(flag == SDL_INIT_VIDEO)
				IMG_Init( IMG_INIT_TIF |
					IMG_INIT_JPG |
					IMG_INIT_PNG);
			toggleService(flag);
		} else {
			if(!isRunning(flag)) {
				SDL_InitSubSystem(flag);
				toggleService(flag);
			} else {
				//TODO: throw already started exception
			}
		}
	}

	void stop(const Uint32& flag) 
	{
		if(isRunning(flag)) {
			SDL_QuitSubSystem(flag);
			toggleService(flag);
			if(noServices()) {
				init = false;
				SDL_Quit();
			}
		}
	}

	/*
	 * Identify whether any service is running
	 * @return - Returns true if no services are running, else false
	 */
	bool noServices() const
	{
		if(timer | audio |
			video |	joystick |
			haptic | gamecontroller |
			events | noparachute) { return false; }
		return true;
	}

	void quit() const
	{
		IMG_Quit();
		SDL_Quit();
	}

} SDLInit;
