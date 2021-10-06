#include <SDL.h>
#include <stdio.h>
#include <thread>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

bool quit = false;
int frame = 0;
void BeginGameLoop() {
	screenSurface = SDL_GetWindowSurface(window);
	int x = SCREEN_WIDTH / 2;
	int y = SCREEN_HEIGHT / 2;
	SDL_Event e;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0, 0));
		frame++;
		//array where you can query scancode of key of whether or not it is pressed down or not
		const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);
		if (keyboard_state_array[SDL_SCANCODE_UP] || keyboard_state_array[SDL_SCANCODE_W]) {
			y += -1;
		}
		if (keyboard_state_array[SDL_SCANCODE_DOWN] || keyboard_state_array[SDL_SCANCODE_S]) {
			y += 1;
		}
		if (keyboard_state_array[SDL_SCANCODE_LEFT] || keyboard_state_array[SDL_SCANCODE_A]) {
			x += -1;
		}
		if (keyboard_state_array[SDL_SCANCODE_RIGHT] || keyboard_state_array[SDL_SCANCODE_D]) {
			x += 1;
		}

		SDL_Rect r;
		r.w = 20;
		r.h = 20;
		r.x = x;
		r.y = y;

		SDL_FillRect(screenSurface, &r, SDL_MapRGB(screenSurface->format, 255, 255, 255));

		SDL_UpdateWindowSurface(window);

		//std::this_thread::sleep_for(std::chrono::milliseconds(16)); //sleep for 16ms eg. ~60fps
	}
}


int main(int argc, char* args[]) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	} else {
		window = SDL_CreateWindow("SDL Learning", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		} else {
			BeginGameLoop();
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}