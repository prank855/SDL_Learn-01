#pragma once

#include <SDL.h>
#include "../System.h"
#include "Graphic.h"
#include <vector>

class RenderSystem : public plx::System {
public:
    RenderSystem() : plx::System("RenderSystem") {};
    void Init();
    void Update();
    void LateUpdate();
    void AddGraphic(Graphic* graphic);
    SDL_Window* window;
    SDL_Color clearColor{ 0,0,0,255 };
private:
    SDL_Renderer* renderer;
    std::vector<Graphic*> graphicQueue;
};