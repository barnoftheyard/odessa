#include "global.h"

void g_draw_testcube(float x_offset, float y_offset, float z_offset)
{
	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
		// Top face (y = 1.0f)
		// Define vertices in counter-clockwise (CCW) order with normal pointing out
		glColor3f(0.0f, 1.0f, 0.0f);     // Green
		glVertex3f( 1.0f + x_offset, 1.0f + y_offset, -1.0f + z_offset);
		glVertex3f(-1.0f + x_offset, 1.0f + y_offset, -1.0f + z_offset);
		glVertex3f(-1.0f + x_offset, 1.0f + y_offset,  1.0f + z_offset);
		glVertex3f( 1.0f + x_offset, 1.0f + y_offset,  1.0f + z_offset);
 
		// Bottom face (y = -1.0f)
		glColor3f(1.0f, 0.5f, 0.0f);     // Orange
		glVertex3f( 1.0f + x_offset, -1.0f + y_offset,  1.0f + z_offset);
		glVertex3f(-1.0f + x_offset, -1.0f + y_offset,  1.0f + z_offset);
		glVertex3f(-1.0f + x_offset, -1.0f + y_offset, -1.0f + z_offset);
		glVertex3f( 1.0f + x_offset, -1.0f + y_offset, -1.0f + z_offset);
 
		// Front face  (z = 1.0f)
		glColor3f(1.0f, 0.0f, 0.0f);     // Red
		glVertex3f( 1.0f + x_offset,  1.0f + y_offset, 1.0f + z_offset);
		glVertex3f(-1.0f + x_offset,  1.0f + y_offset, 1.0f + z_offset);
		glVertex3f(-1.0f + x_offset, -1.0f + y_offset, 1.0f + z_offset);
		glVertex3f( 1.0f + x_offset, -1.0f + y_offset, 1.0f + z_offset);
 
		// Back face (z = -1.0f)
		glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
		glVertex3f( 1.0f + x_offset, -1.0f + y_offset, -1.0f + z_offset);
		glVertex3f(-1.0f + x_offset, -1.0f + y_offset, -1.0f + z_offset);
		glVertex3f(-1.0f + x_offset,  1.0f + y_offset, -1.0f + z_offset);
		glVertex3f( 1.0f + x_offset,  1.0f + y_offset, -1.0f + z_offset);
 
		// Left face (x = -1.0f)
		glColor3f(0.0f, 0.0f, 1.0f);     // Blue
		glVertex3f(-1.0f + x_offset,  1.0f + y_offset,  1.0f + z_offset);
		glVertex3f(-1.0f + x_offset,  1.0f + y_offset, -1.0f + z_offset);
		glVertex3f(-1.0f + x_offset, -1.0f + y_offset, -1.0f + z_offset);
		glVertex3f(-1.0f + x_offset, -1.0f + y_offset,  1.0f + z_offset);
 
		// Right face (x = 1.0f)
		glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
		glVertex3f(1.0f + x_offset,  1.0f + y_offset, -1.0f + z_offset);
		glVertex3f(1.0f + x_offset,  1.0f + y_offset,  1.0f + z_offset);
		glVertex3f(1.0f + x_offset, -1.0f + y_offset,  1.0f + z_offset);
		glVertex3f(1.0f + x_offset, -1.0f + y_offset, -1.0f + z_offset);
	glEnd();  // End of drawing color-cube
}

void g_window_resize(int new_width, int new_height)
{
	screen_width = new_width;
	screen_height = new_height;
	
    if(screen_height == 0)
    {
		screen_height = 1;
	}
    glViewport(0, 0, screen_width, screen_height);
    
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    //Set FOV
	gluPerspective(FOV, (float)screen_width / (float)screen_height, 0.1, 100);
    
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
