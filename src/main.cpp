#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <thread>
#include <iostream>

#define FPS_UNLIMITED 0
#define FPS_500 2
#define FPS_333 3
#define FPS_250 4
#define FPS_200 5
#define FPS_166 6
#define FPS_125 8
#define FPS_100 10
#define FPS_60 16
#define FPS_30 32

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int FRAMETIME_LIMIT = FPS_500;
SDL_Window* window = NULL;
SDL_Renderer* renderer;

bool quit = false;
int frame = 0;
void BeginGameLoop() {



	SDL_Event e;

	//timing init
	auto start = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds lastTime;

	SDL_Texture* pokiTexture = NULL;
	SDL_Surface* surface = IMG_Load(".\\resources\\poki.bmp");
	if (surface) {
		pokiTexture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
	} else {
		std::cout << "WADAFAK??" << std::endl;
	}

	float x = SCREEN_WIDTH / 2;
	float y = SCREEN_HEIGHT / 2;
	float speed = 50;

	while (!quit) {
		frame++;

		//delta time calculations
		auto now = std::chrono::high_resolution_clock::now() - start;
		std::chrono::duration<float> delta = now - lastTime;
		float deltaTime = delta.count();
		lastTime = now;

		//check for exit button
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}

		//clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		//movement stuff
		{
			//array where you can query scancode of key of whether or not it is pressed down or not
			const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);
			if (keyboard_state_array[SDL_SCANCODE_UP] || keyboard_state_array[SDL_SCANCODE_W]) {
				y += -speed * deltaTime;
			}
			if (keyboard_state_array[SDL_SCANCODE_DOWN] || keyboard_state_array[SDL_SCANCODE_S]) {
				y += speed * deltaTime;
			}
			if (keyboard_state_array[SDL_SCANCODE_LEFT] || keyboard_state_array[SDL_SCANCODE_A]) {
				x += -speed * deltaTime;
			}
			if (keyboard_state_array[SDL_SCANCODE_RIGHT] || keyboard_state_array[SDL_SCANCODE_D]) {
				x += speed * deltaTime;
			}}

		//init rectangle: posx,posy,width,height
		SDL_Rect r = { (int)x,(int)y,88,88 };

		//draw sprite
		SDL_RenderCopy(renderer, pokiTexture, NULL, &r);

		//present back buffer
		SDL_RenderPresent(renderer);

		//fps limiter
		if (FRAMETIME_LIMIT - 1 > 0) {
			SDL_Delay(FRAMETIME_LIMIT - 1);
		}

	}
}


int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	window = SDL_CreateWindow("SDL Learning", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	BeginGameLoop();

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}