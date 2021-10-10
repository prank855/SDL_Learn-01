/*
	//load and draw image
	SDL_Texture* pokiTexture = NULL;
	SDL_Surface* surface = IMG_Load(".\\resources\\poki.bmp");
	if (surface) {
		pokiTexture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		SDL_RenderCopy() whatever then fuck etc
	}

	//keyboard input
	const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);
	example: keyboard_state_array[SDL_SCANCODE_UP]
*/

#include "Application.h"
int main(int argc, char* args[]) {
	Application a;
	return 0;
}