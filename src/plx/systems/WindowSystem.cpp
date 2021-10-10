#include <SDL.h>
#include "WindowSystem.h"
#include "../Engine.h"

void WindowSystem::Init() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Unnamed Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
}

void WindowSystem::SetTitle(const char* titleName) {
    SDL_SetWindowTitle(window, titleName);
}

SDL_Window* WindowSystem::getWindow() {
    return window;
}

void WindowSystem::Start() {}

void WindowSystem::Update() {
    //check for window event, such as exit button / window moving etc
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            engine->isRunning = false;
        }
    }
}