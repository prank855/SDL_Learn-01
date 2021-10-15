#pragma once

#include "Graphic.h"

#include "../Vec2.h"

#include <iostream>
class RectangleGraphic : public Graphic {
public:
    plx::Vec2 position;
    float width = 20;
    float height = 20;
    SDL_Color color{ 255,255,255,255 };
private:
    void Render(SDL_Renderer* renderer) {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_FRect r = { position.x,position.y, width, height };
        SDL_RenderFillRectF(renderer, &r);
    }
};