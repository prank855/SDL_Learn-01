#pragma once

#include <SDL.h>
#include "../System.h"

class RenderSystem : public plx::System {
public:
    RenderSystem() : plx::System("RenderSystem") {};
    void Init();
    void Update();
    void LateUpdate();
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Color clearColor{ 0,0,0,255 };
};