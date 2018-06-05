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

void g_init();
void g_render();
void g_update();
void g_close();
void g_renderinit();

void g_keyinput(const Uint8* g_keyinput);
void g_mouseinput(SDL_Event event);
void g_window_resize(int width, int height);

const Uint8* g_keystate;

void r_draw_testcube();
void r_draw_texcube();
void r_draw_texquad(float tex_scale, float size);
GLuint r_loadtexture(char* filepath);

SDL_Window* g_window;
SDL_GLContext g_context;

int screen_width;
int screen_height;

int FOV;

float deg2rad(float deg);

float delta;

float mouse_sense;

bool capture_mouse;

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

struct g_plyrdata g_plyr;

#endif
