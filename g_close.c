#include "global.h"

void g_close()
{
	//Destroy context and window
    SDL_GL_DeleteContext(g_context);
	SDL_DestroyWindow(g_window);

	//Quit SDL subsystems
	SDL_Quit();
}

