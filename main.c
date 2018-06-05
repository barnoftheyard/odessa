#include "global.h"

int main(int argc, char* args[])
{
	int current_time;
	int previous_time;
	bool quit = false;													//Main loop flag
	
	g_init();
	
	SDL_Event event;													//Event handler
	const Uint8* g_keystate = SDL_GetKeyboardState(NULL);				//Get current key state

	while(!quit)														//The main game loop
	{
		while(SDL_PollEvent(&event))									//Handle events on queue
		{
			if(event.type == SDL_QUIT)
			{
				quit = true;
			}
			else if(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
            {
                g_window_resize(event.window.data1, event.window.data2);
            }
			else if(event.type == SDL_MOUSEMOTION)
            {
                g_mouseinput(event);
            }
		}
		g_keyinput(g_keystate);											//Check for key states
		
		g_render();														//Render the game, called every tick
		
		current_time = SDL_GetTicks();
		delta = (float)(current_time - previous_time) / 1000;			//Gets the delta
		previous_time = current_time; 
		
	}
	g_close();												//Free resources and close SDL

	return 0;
}
