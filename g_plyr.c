#include "global.h"

struct g_plyrdata g_plyr = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 22.0f};

struct vector3 direction = {0, 0, 0};

float mouse_sense = 0.25;
float mouse_x = 0;
float mouse_y = 0;

void clamp_camera()														//Clamp pitch to 90 and -90 and wrap 360 all around
{
	if(g_plyr.pitch > 90.0f)
	{
		g_plyr.pitch = 90.0f;
	}
	else if(g_plyr.pitch < -90.0f)
		{
		g_plyr.pitch = -90.0f;
		}
	if(g_plyr.yaw <=0.0f)
	{
		g_plyr.yaw += 360.0f;
	}
	else if(g_plyr.yaw > 360.0f)
	{
		g_plyr.yaw -= 360.0f;
	}
}

void g_keyinput(SDL_Event event)
{
	switch(event.key.keysym.sym)
	{
		case SDLK_w:
			g_plyr.x += sin(deg2rad(direction.x)) * g_plyr.speed * delta;			//Use sine and cosine to linear interpolate
			g_plyr.y += -sin(deg2rad(direction.y)) * g_plyr.speed * delta;
			g_plyr.z += cos(deg2rad(direction.z)) * g_plyr.speed * delta;
			break;
		case SDLK_s:
			g_plyr.x -= sin(deg2rad(direction.x)) * g_plyr.speed * delta;
			g_plyr.y -= -sin(deg2rad(direction.y)) * g_plyr.speed * delta;
			g_plyr.z -= cos(deg2rad(direction.z)) * g_plyr.speed * delta;
			break;
			
		case SDLK_a:
			g_plyr.x += sin(deg2rad(direction.x + 90)) * g_plyr.speed * delta;		//Add 90 degrees to make motion horizonal
			g_plyr.z += cos(deg2rad(direction.z + 90)) * g_plyr.speed * delta;
			break;
		case SDLK_d:
			g_plyr.x -= sin(deg2rad(direction.x + 90)) * g_plyr.speed * delta;
			g_plyr.z -= cos(deg2rad(direction.z + 90)) * g_plyr.speed * delta;
			break;
			
		case SDLK_SPACE:
			g_plyr.y -= g_plyr.speed * delta;
			printf("space\n");
			break;
		case SDLK_e:
			g_plyr.y += g_plyr.speed * delta;
			printf("e\n");
			break;
			
		case SDLK_UP:
			g_plyr.pitch -= 100.0f * delta;
			direction.y = -g_plyr.pitch;
			break;
		case SDLK_LEFT:
			g_plyr.yaw -= 100.0f * delta;
			direction.x = -g_plyr.yaw;
			//direction.y = g_plyr.yaw;
			direction.z = -g_plyr.yaw;
			break;
		case SDLK_DOWN:
			g_plyr.pitch += 100.0f * delta;
			direction.y = -g_plyr.pitch;
			break;
		case SDLK_RIGHT:
			g_plyr.yaw += 100.0f * delta;
			direction.x = -g_plyr.yaw;
			//direction.y = g_plyr.yaw;
			direction.z = -g_plyr.yaw;
			break;
	}
	
	clamp_camera();
	
	//Prints the current player's position
	printf("x: %f y: %f z: %f\n", g_plyr.x, g_plyr.y, g_plyr.z);
	printf("pitch: %f yaw: %f roll: %f\n", g_plyr.pitch, g_plyr.yaw, g_plyr.roll);
	
}

void g_mouseinput(SDL_Event event)
{
	SDL_ShowCursor(SDL_DISABLE);
	
	g_plyr.yaw -= mouse_sense * (screen_width / 2 - event.motion.x);
	g_plyr.pitch -= mouse_sense * (screen_height / 2 - event.motion.y);
	
	direction.x = -g_plyr.yaw;
	direction.y = -g_plyr.pitch;
	direction.z = -g_plyr.yaw;
	
	clamp_camera();
	
	SDL_WarpMouseInWindow(g_window, screen_width / 2, screen_height / 2);
	
}
