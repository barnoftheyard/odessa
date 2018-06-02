#include "global.h"

int main(int argc, char* args[])
{
	g_init();
	
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event event;

	//The main game loop. Everything that is refrenced here is repeated within the game.
	while(!quit)
	{
		//Handle events on queue
		while(SDL_PollEvent(&event))
		{
			//User requests quit
			if(event.type == SDL_QUIT)
			{
				quit = true;
			}
			else if(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
            {
                g_window_resize(event.window.data1, event.window.data2);
            }
			//Handle keypress with current mouse position
			else if(event.type == SDL_KEYDOWN)
			{
				g_keyinput(event);
			}
			else if(event.type == SDL_MOUSEMOTION)
            {
                g_mouseinput(event);
            }
			
		}
		//Render the game. Called every tick.
		g_render();
		
		//Gets the delta
		thisTime = SDL_GetTicks();
		delta = (float)(thisTime - lastTime) / 1000;
		lastTime = thisTime; 
		
	}
	//Free resources and close SDL
	g_close();

	return 0;
}
