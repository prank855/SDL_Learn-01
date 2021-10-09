#pragma once

#include <SDL.h>
#include "../System.h"

class RenderSystem : public plx::System {
public:
    RenderSystem() : plx::System("RenderSystem") {};
    void Init();
    void Start();
    void Update();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};