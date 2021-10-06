#include <SDL.h>
#include <stdio.h>
#include <thread>
#include <iostream>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
SDL_Window* window = NULL;
SDL_Renderer* renderer;

bool quit = false;
int frame = 0;
void BeginGameLoop() {
	float x = SCREEN_WIDTH / 2;
	float y = SCREEN_HEIGHT / 2;
	SDL_Event e;
	auto start = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds lastTime;
	while (!quit) {
		auto now = std::chrono::high_resolution_clock::now() - start;
		std::chrono::duration<float> delta = now - lastTime;
		float deltaTime = delta.count();
		lastTime = now;

		//std::cout << "FPS: " << 1 / delta.count() << "\n";

		//check for exit
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}

		//clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		frame++;

		//array where you can query scancode of key of whether or not it is pressed down or not
		int speed = 50;
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
		}

		SDL_Rect r;
		r.w = 20;
		r.h = 20;
		r.x = x;
		r.y = y;

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &r);

		SDL_RenderPresent(renderer);

		SDL_Delay(1000 / 240);
	}
}


int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("SDL Learning", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
	BeginGameLoop();
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}