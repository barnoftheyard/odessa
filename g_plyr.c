#include "global.h"

struct g_plyrdata g_plyr = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 22.0f};

struct vector3 direction = {0, 0, 0};

float mouse_sense = 0.25;
float mouse_x = 0;
float mouse_y = 0;

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
			g_plyr.x += sin(deg2rad(direction.x + 90)) * g_plyr.speed * delta;
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
	//Prints the current player's position
	printf("x: %f y: %f z: %f\n", g_plyr.x, g_plyr.y, g_plyr.z);
	printf("pitch: %f yaw: %f roll: %f\n", g_plyr.pitch, g_plyr.yaw, g_plyr.roll);
	
}

void g_mouseinput(SDL_Event event)
{
	/*SDL_SetRelativeMouseMode(SDL_TRUE);
    mouse_x += event.motion.x;
    mouse_y += event.motion.y;
    
    mouse_x * mouse_sense;
    mouse_y * mouse_sense;
    
    
    if(mouse_y > 90.0f)
    {
		mouse_y = 90.0f;
	}
	else if(mouse_y < -90.0f)
	{
		mouse_y = -90.0f;
	}
    if(mouse_x > 360.0f)
    {
		mouse_x = 0.0f;
	}
	
	g_plyr.pitch = -mouse_y;
	g_plyr.yaw = -mouse_x;
	direction = g_plyr.yaw;
    
    printf("%f, %f\n", mouse_x, mouse_y);*/
}
