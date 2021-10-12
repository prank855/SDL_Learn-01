#include "RectangleComponent.h"
#include "../Node.h"

#include "../Engine.h"
#include "../systems/RenderSystem.h"

#include <iostream>

#include <SDL.h>

void RectangleComponent::Update() {
    auto e = plx::Engine::self;
    if (e != nullptr) {
        auto rs = e->GetSystem<RenderSystem>();
        if (rs != nullptr) {
            auto renderer = rs->renderer;
            if (renderer != nullptr) {
                SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
                SDL_FRect r = { parent->position.x,parent->position.y, 40,40 };
                SDL_RenderFillRectF(renderer, &r);
            }
        }

    }

}