/*
void BeginGameLoop() {
	bool quit = false;
	int frame = 0;

	//event manager
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

	while (!quit) {
		frame++;
		//delta time calculations
		auto now = std::chrono::high_resolution_clock::now() - start;
		std::chrono::duration<float> delta = now - lastTime;
		const float deltaTime = delta.count();
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

		//const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);
		//example: keyboard_state_array[SDL_SCANCODE_UP]


		//draw sprite
		SDL_Rect r = { (int)SCREEN_WIDTH / 2,(int)SCREEN_HEIGHT / 2,88,88 };
		SDL_RenderCopy(renderer, pokiTexture, NULL, &r);

		//present back buffer
		SDL_RenderPresent(renderer);

		//fps limiter
		if (FRAMETIME_LIMIT - 1 > 0) {
			SDL_Delay(FRAMETIME_LIMIT - 1);
		}

	}
}
*/

#include "Application.h"
int main(int argc, char* args[]) {
	Application a;
	return 0;
}