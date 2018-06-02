#include "global.h"

int g_init()
{
	
	//Initializes SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "SDL init fuckup. Send this to a codenigger. %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}
	
	//Sets what OpenGL context we use
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
	
	//Creates the SDL window.
	g_window = SDL_CreateWindow(
        GAME_NAME, 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        screen_width, screen_height, 
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
    );
    
	if(g_window == NULL)
	{
        fprintf(stderr, "SDL window creation fuckup. Send this to a codenigger. %s\n", SDL_GetError());
        return EXIT_FAILURE;
	}
	
	
	//Creats the window context
	g_context = SDL_GL_CreateContext(g_window);
	if(g_context == NULL)
	{
		fprintf(stderr, "SDL window context fuckup. Send this to a codenigger. %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}
	
	glClearColor(0.5, 0.69, 1.0, 1);									//Set color of the sky (background)
    
    glEnable(GL_DEPTH_TEST);                       						//Enables Depth Testing
	
	glViewport(0, 0, screen_width, screen_height);						//Set the size of the viewport.
    
    //To operate on the Projection matrix.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(90, (float)screen_width / (float)screen_height, 0.1, 100);
    
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	
    //Error handling for OpenGL
	GLenum gl_error = glGetError();
	if(gl_error != GL_NO_ERROR)
	{
		fprintf(stderr, "OpenGL fuckup. Send this to a codenigger. %s\n", gluErrorString(gl_error));
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}
