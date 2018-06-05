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

void g_keyinput(const Uint8* keystate)
{
	if(keystate[SDL_SCANCODE_W])
	{
		g_plyr.x += sin(deg2rad(direction.x)) * g_plyr.speed * delta;			//Use sine and cosine to linear interpolate
		g_plyr.y += -sin(deg2rad(direction.y)) * g_plyr.speed * delta;
		g_plyr.z += cos(deg2rad(direction.z)) * g_plyr.speed * delta;
	}
	if(keystate[SDL_SCANCODE_S])
	{
		g_plyr.x -= sin(deg2rad(direction.x)) * g_plyr.speed * delta;
		g_plyr.y -= -sin(deg2rad(direction.y)) * g_plyr.speed * delta;
		g_plyr.z -= cos(deg2rad(direction.z)) * g_plyr.speed * delta;
	}
			
	if(keystate[SDL_SCANCODE_A])
	{
		g_plyr.x += sin(deg2rad(direction.x + 90)) * g_plyr.speed * delta;		//Add 90 degrees to make motion horizonal
		g_plyr.z += cos(deg2rad(direction.z + 90)) * g_plyr.speed * delta;
	}
	if(keystate[SDL_SCANCODE_D])
	{
		g_plyr.x -= sin(deg2rad(direction.x + 90)) * g_plyr.speed * delta;
		g_plyr.z -= cos(deg2rad(direction.z + 90)) * g_plyr.speed * delta;
	}
			
	if(keystate[SDL_SCANCODE_SPACE])
	{
		g_plyr.y -= g_plyr.speed * delta;
	}
	if(keystate[SDL_SCANCODE_E])
	{
		g_plyr.y += g_plyr.speed * delta;
	}
			
	if(keystate[SDL_SCANCODE_UP])
	{
		g_plyr.pitch -= 100.0f * delta;
		direction.y = -g_plyr.pitch;
	}
	if(keystate[SDL_SCANCODE_LEFT])
	{
		g_plyr.yaw -= 100.0f * delta;
		direction.x = -g_plyr.yaw;
		//direction.y = g_plyr.yaw;
		direction.z = -g_plyr.yaw;
	}
	if(keystate[SDL_SCANCODE_DOWN])
	{
		g_plyr.pitch += 100.0f * delta;
		direction.y = -g_plyr.pitch;
	}
	if(keystate[SDL_SCANCODE_RIGHT])
	{
		g_plyr.yaw += 100.0f * delta;
		direction.x = -g_plyr.yaw;
		//direction.y = g_plyr.yaw;
		direction.z = -g_plyr.yaw;
	}
			
	if(keystate[SDL_SCANCODE_ESCAPE])
	{
		capture_mouse = !capture_mouse;
	}
	
	clamp_camera();
	
	printf("x: %f y: %f z: %f\n", g_plyr.x, g_plyr.y, g_plyr.z);
	printf("pitch: %f yaw: %f roll: %f\n", g_plyr.pitch, g_plyr.yaw, g_plyr.roll);
}

void g_mouseinput(SDL_Event event)
{
	if(capture_mouse)
	{
		SDL_ShowCursor(SDL_DISABLE);
		SDL_WarpMouseInWindow(g_window, screen_width / 2, screen_height / 2);
		
		g_plyr.yaw -= mouse_sense * (screen_width / 2 - event.motion.x);
		g_plyr.pitch -= mouse_sense * (screen_height / 2 - event.motion.y);
	
		direction.x = -g_plyr.yaw;
		direction.y = -g_plyr.pitch;
		direction.z = -g_plyr.yaw;
	
		clamp_camera();
	}
	else
	{
		SDL_ShowCursor(SDL_ENABLE);
	}
}
