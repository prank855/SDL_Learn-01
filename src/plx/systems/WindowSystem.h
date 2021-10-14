#pragma once

#include <SDL.h>
#include "../System.h"

class WindowSystem : public plx::System {
public:
    WindowSystem() : plx::System("WindowSystem") {
    };
    void Init();
    void Start();
    void Update();
    void SetTitle(const char*);
    void SetWindowSize(int w, int h);
    SDL_Window* getWindow();
    const bool isFullscreen = &m_isFullScreen;
private:
    int windowed_width = 1280;
    int windowed_height = 720;
    SDL_Window* window;
    SDL_Event e;
    bool m_isFullScreen = false;
    bool F11_pressed = false;
};