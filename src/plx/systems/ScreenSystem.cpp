#include <SDL.h>
#include "ScreenSystem.h"
#include "../Engine.h"

void ScreenSystem::Init() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Unnamed Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
}

void ScreenSystem::SetTitle(const char* titleName) {
    SDL_SetWindowTitle(window, titleName);
}

SDL_Window* ScreenSystem::getWindow() {
    return window;
}

void ScreenSystem::Start() {}

void ScreenSystem::Update() {
    //check for window event, such as exit button / window moving etc
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            engine->isRunning = false;
        }
    }
}