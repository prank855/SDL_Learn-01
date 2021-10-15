#include "RenderSystem.h"
#include "WindowSystem.h"
#include "../Engine.h"
#include "../System.h"

#include <iostream>
#include <cmath>

void RenderSystem::Init() {
    // get window instance
    window = plx::Engine::self->GetSystem<WindowSystem>()->getWindow();
    if (window != nullptr) {
        // if window exists create renderer
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }
}

#include "TimeSystem.h"
void RenderSystem::Update() {
    if (renderer != nullptr) {
        // sets clear color
        SDL_SetRenderDrawColor(renderer, clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        // clear screen
        SDL_RenderClear(renderer);
    }
}

void RenderSystem::AddGraphic(Graphic* graphic) {
    this->graphicQueue.push_back(graphic);
}

#include "TimeSystem.h"
void RenderSystem::LateUpdate() {
    if (renderer != nullptr) {
        //draw shit here
        for (auto graphic : graphicQueue) {
            graphic->Render(renderer);
            delete graphic;
        }
        graphicQueue.clear();

        // present/show rendered frame
        SDL_RenderPresent(renderer);
        SDL_Delay(1); //hardcoded fps limiter (2ms ~500fps, because sdl_delay seems to always add 1ms to it)
    }
}