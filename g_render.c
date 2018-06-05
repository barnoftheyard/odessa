#include "global.h"

float i = 0.0f;

GLuint wood_panel;
GLuint grass_top;

GLuint r_loadtexture(char* filepath)
{
	GLuint id;
	SDL_Surface* texture = SDL_LoadBMP(filepath);
	if(texture == NULL)
	{
		fprintf(stderr, "SDL init fuckup. Send this to a codenigger. %s\n", SDL_GetError());
		g_close();
		exit(EXIT_FAILURE);
	}
	
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture -> w, texture -> h, 0, GL_RGB,
	GL_UNSIGNED_SHORT_5_6_5, texture -> pixels);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	
	SDL_FreeSurface(texture);
	
	return id;
}

void g_renderinit()
{
	wood_panel = r_loadtexture("./textures/wood_panel.bmp");
	grass_top = r_loadtexture("./textures/grass_top.bmp");
}

void g_render()
{
    //Clears the screen and the depth. Make sure to not remove this, it projects the polygons normally
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glRotatef(g_plyr.pitch, 1.0f, 0, 0);                 				//Rotate the pitch
	glRotatef(g_plyr.yaw, 0, 1.0f, 0);                  				//Rotate the yaw
	
	glTranslatef(g_plyr.x, g_plyr.y, g_plyr.z);							//Move player to new position
    
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -4.0f);
    glColor3f(1, 1, 1);
    glRotatef(i, 0, 1.0f, 0);
    i += 10 * delta;
    if(i > 360)
    {
		i = 0;
	}
    r_draw_texcube();
    glPopMatrix();
    
    glPushMatrix();														//Wood cube
    glBindTexture(GL_TEXTURE_2D, wood_panel);
    glTranslatef(4.0f, 0.0f, -4.0f);
    r_draw_texcube();
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-4.0f, 0.0f, -4.0f);
    glColor3f(1, 1, 1);
    r_draw_texcube();
    glPopMatrix();
    
    glBindTexture(GL_TEXTURE_2D, grass_top);
    glTranslatef(0.0f, -4.0f, 0.0f);
    r_draw_texquad(5.0f, 10.0f);
    glBindTexture(GL_TEXTURE_2D, 0);
    
 
    //This function swaps the back buffer ( were we are currently drawing ) with the front buffer ( the one currently on the screen)
	SDL_GL_SwapWindow(g_window);
}
