#include <SDL.h>
#include "WindowSystem.h"
#include "../Engine.h"

void WindowSystem::Init() {
    SDL_Init(SDL_INIT_VIDEO);
    m_window = SDL_CreateWindow("Unnamed Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_windowed_width, m_windowed_height, SDL_WINDOW_SHOWN);
}

void WindowSystem::SetTitle(const char* titleName) {
    SDL_SetWindowTitle(m_window, titleName);
}

void WindowSystem::SetWindowSize(int w, int h) {
    m_windowed_width = w;
    m_windowed_height = h;
    std::cout << "Window size set to " << w << "x" << h << "\n";
}

SDL_Window* WindowSystem::getWindow() {
    return m_window;
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

    // keyboard input array
    const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);
    if (keyboard_state_array[SDL_SCANCODE_F11]) {
        if (!F11_pressed) {
            if (!m_isFullScreen) {
                m_isFullScreen = true;
                SDL_DisplayMode DM;

                SDL_GetCurrentDisplayMode(0, &DM);

                SDL_SetWindowSize(m_window, DM.w, DM.h);
                SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN);

                std::cout << "Entered Fullscreen Mode: " << DM.w << "x" << DM.h << "p@" << DM.refresh_rate << "hz\n";
            } else {
                m_isFullScreen = false;
                SDL_DisplayMode DM;

                SDL_SetWindowFullscreen(m_window, 0);
                SDL_SetWindowSize(m_window, m_windowed_width, m_windowed_height);

                std::cout << "Entered Windowed Mode: " << m_windowed_width << "x" << windowed_height << "p\n";
            }
        }
        F11_pressed = true;
    } else {
        F11_pressed = false;
    }

}