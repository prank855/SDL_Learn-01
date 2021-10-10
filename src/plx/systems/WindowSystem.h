#pragma once

#include <SDL.h>
#include "../System.h"

class WindowSystem : public plx::System {
public:
    WindowSystem() : plx::System("ScreenSystem") {
    };
    void Init();
    void Start();
    void Update();
    void SetTitle(const char*);
    SDL_Window* getWindow();
private:
    SDL_Window* window;
    SDL_Event e;
};