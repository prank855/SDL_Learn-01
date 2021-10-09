#include "RenderSystem.h"
#include "ScreenSystem.h"
#include "../Engine.h"
#include "../System.h"

#include <iostream>

void RenderSystem::Init() {
    auto temp = engine->GetSystem<ScreenSystem>();
    window = temp->getWindow();
    if (window != nullptr) {
        std::cout << "WORKS?" << std::endl;
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }
}

void RenderSystem::Start() {

}

void RenderSystem::Update() {
    if (renderer != nullptr) {
        //clear screen
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderClear(renderer);

        //do draw calls here
        int w, h;
        SDL_GetWindowSize(window, &w, &h);

        //draw rectangle in middle of screen
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect r = { w / 2,h / 2, 40,40 };
        SDL_RenderFillRect(renderer, &r);

        SDL_RenderPresent(renderer);

        SDL_Delay(5); //hardcoded fps limiter (6ms ~166fps, because sdl_delay seems to always add 1ms to it)
    }
}