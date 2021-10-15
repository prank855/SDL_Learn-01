#pragma once
#include <SDL.h>
#include "../Component.h"

class RectangleComponent : public plx::Component {
public:
    RectangleComponent() : plx::Component("RectangleComponent") {};
    void Update();
    unsigned int width = 20;
    unsigned int height = 20;
    SDL_Color color{ 255,255,255,255 };
};