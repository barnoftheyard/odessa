#ifndef GAMEDEF_H
#define GAMEDEF_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_image.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define GAME_NAME "JEWBOY DELUXO PARAMILLITARY 32 bit SCIMPVISION from india with  l o v e"

/*
UNTITLED GAME. VERSION 0.1
Hey you slimey kikes and welcome the gamedef header. This is the heart of the
game's definations and is akin to the quakedef.h file in Quake 1.
Ukrainian Nationalist Authority over Territorial Control of Oblasts
*/

int g_init();
void g_render();
void g_update();
void g_close();
void g_keyinput(SDL_Event event);
void g_mouseinput(SDL_Event event);
void g_window_resize(int width, int height);
void g_draw_testcube(float x_offset, float y_offset, float z_offset);

extern SDL_Window* g_window;
extern SDL_GLContext g_context;

extern int screen_width;
extern int screen_height;

extern float deg2rad(float deg);

extern float delta;
extern int thisTime;
extern int lastTime;

extern float mouse_sense;

struct g_plyrdata
{
	float x;
	float y;
	float z;
	float pitch;
	float yaw;
	float roll;
	float speed;
};

struct vector3
{
	float x;
	float y;
	float z;
};

extern struct g_plyrdata g_plyr;

#endif
