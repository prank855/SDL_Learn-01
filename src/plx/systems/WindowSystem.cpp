#include <SDL.h>
#include "WindowSystem.h"
#include "../Engine.h"

void WindowSystem::Init() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Unnamed Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowed_width, windowed_height, SDL_WINDOW_SHOWN);
}

void WindowSystem::SetTitle(const char* titleName) {
    SDL_SetWindowTitle(window, titleName);
}

void WindowSystem::SetWindowSize(int w, int h) {
    windowed_width = w;
    windowed_height = h;
    std::cout << "Window size set to " << w << "x" << h << "\n";
}

SDL_Window* WindowSystem::getWindow() {
    return window;
}

void WindowSystem::Start() {}

#include <iostream>

void WindowSystem::Update() {
    //check for window event, such as exit button / window moving etc
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            engine->isRunning = false;
        }
    }

    const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);


    if (keyboard_state_array[SDL_SCANCODE_F11]) {
        if (!F11_pressed) {
            if (!m_isFullScreen) {
                m_isFullScreen = true;
                SDL_DisplayMode DM;
                SDL_GetCurrentDisplayMode(0, &DM);
                std::cout << "Entering Fullscreen Mode: " << DM.w << "x" << DM.h << "p@" << DM.refresh_rate << "hz\n";
                SDL_SetWindowSize(window, DM.w, DM.h);
                SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
            } else {
                m_isFullScreen = false;
                SDL_DisplayMode DM;
                SDL_SetWindowFullscreen(window, 0);
                SDL_SetWindowSize(window, windowed_width, windowed_height);
                std::cout << "Leaving Fullscreen Mode\n";
            }
        }
        F11_pressed = true;
    } else {
        F11_pressed = false;
    }

}