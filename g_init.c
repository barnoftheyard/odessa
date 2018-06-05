#include "global.h"

void g_init()
{

	if(SDL_Init(SDL_INIT_VIDEO) < 0)									//Initializes SDL
	{
		fprintf(stderr, "SDL init fuckup. Send this to a codenigger. %s\n", SDL_GetError());
		g_close();
		exit(EXIT_FAILURE);
	}
	
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
	g_window = SDL_CreateWindow(										//Creates the SDL window
        GAME_NAME, 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        screen_width, screen_height, 
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
    );
    
	if(g_window == NULL)
	{
        fprintf(stderr, "SDL window creation fuckup. Send this to a codenigger. %s\n", SDL_GetError());
        g_close();
        exit(EXIT_FAILURE);
	}
	
	
	//Creats the window context
	g_context = SDL_GL_CreateContext(g_window);
	if(g_context == NULL)
	{
		fprintf(stderr, "SDL window context fuckup. Send this to a codenigger. %s\n", SDL_GetError());
		g_close();
		exit(EXIT_FAILURE);
	}
	
	glClearColor(0.5, 0.69, 1.0, 1);									//Set color of the sky (background)
    
	glViewport(0, 0, screen_width, screen_height);						//Set the size of the viewport.
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(FOV, (float)screen_width / (float)screen_height, 0.1, 100);
    
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glEnable(GL_DEPTH_TEST);                       						//Enables Depth Testing
	glEnable(GL_TEXTURE_2D);
	
	g_renderinit();
	
	GLenum gl_error = glGetError();										//Error handling for OpenGL
	if(gl_error != GL_NO_ERROR)
	{
		fprintf(stderr, "OpenGL fuckup. Send this to a codenigger. %s\n", gluErrorString(gl_error));
		g_close();
		exit(EXIT_FAILURE);
	}
	
}
