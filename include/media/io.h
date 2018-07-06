#ifndef _IO_H
#define _IO_H

#include <SDL2/SDL.h>
#include <unordered_map>
#include <functional>

typedef std::unordered_map<size_t, std::function<void()>> FunctionMap;

class Io 
{
	FunctionMap keyBindings;
	SDL_Event event;

	void executeMapEvent(const Uint32& event, const FunctionMap& functMap);
	
public:
	/// This method should get called at every iteration
	/// of the loop wether it is in another thread or in a
	/// main loop with all the other services. This tick function
	/// checks for all active event inputs availble and executes the
	/// associated callback function to that event.
	void tick();

	void setKeyBinding(const size_t& keyCode, const std::function<void()>& funct);
};

#endif // _IO_H
