#include "RenderSystem.h"
#include "WindowSystem.h"
#include "../Engine.h"
#include "../System.h"

#include <iostream>

void RenderSystem::Init() {
    // get window instance
    window = engine->GetSystem<WindowSystem>()->getWindow();;
    if (window != nullptr) {
        // if window exists create renderer
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }
}

void RenderSystem::Start() {

}

#include "TimeSystem.h"
void RenderSystem::Update() {
    if (renderer != nullptr) {
        // sets clear color
        SDL_SetRenderDrawColor(renderer, clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        // clear screen
        SDL_RenderClear(renderer);

        //do draw calls here

        /*Temporary Code*/ { // draws rectangle scrolling across screen

            //get window size
            int w, h; SDL_GetWindowSize(window, &w, &h);

            //if position offscreen, kill program
            int speed = 50;
            if ((int)(TimeSystem::elapsed * speed) >= w) {
                engine->isRunning = false;
            } else {

                // set draw color
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

                // create rect
                SDL_Rect r = { (int)(TimeSystem::elapsed * speed), h / 2, 40,40 };

                // draw rect
                SDL_RenderFillRect(renderer, &r);
            }
        }

        // present/show rendered frame
        SDL_RenderPresent(renderer);

        SDL_Delay(5); //hardcoded fps limiter (6ms ~166fps, because sdl_delay seems to always add 1ms to it)
    }
}