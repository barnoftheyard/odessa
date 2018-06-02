#include "global.h"

float i = 0.0f;

void g_render()
{
    //Clears the screen and the depth. Make sure to not remove this, it projects the polygons normally
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glRotatef(g_plyr.pitch, 1.0f, 0, 0);                 				// Rotate Up And Down To Look Up And Down
	glRotatef(g_plyr.yaw, 0, 1.0f, 0);                  				// Rotate Depending On Direction Player Is Facing
	
	glTranslatef(g_plyr.x, g_plyr.y, g_plyr.z);							//Move player to new position
	
    
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -4.0f);
    glRotatef(i, 0, 1.0f, 0);
    i += 10 * delta;
    if(i > 360)
    {
		i = 0;
	}
    g_draw_testcube(0.0f, 0.0f, 0.0f);
    glPopMatrix();
    
    glTranslatef(-4.0f, 0.0f, -4.0f);
    g_draw_testcube(0.0f, 0.0f, 0.0f);
    
    glTranslatef(8.0f, 0.0f, 0.0f);
    g_draw_testcube(0.0f, 0.0f, 0.0f);
    glLoadIdentity();
 
    //This function swaps the back buffer ( were we are currently drawing ) with the front buffer ( the one currently on the screen)
	SDL_GL_SwapWindow(g_window);
}
