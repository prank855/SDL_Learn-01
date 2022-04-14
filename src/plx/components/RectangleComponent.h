#pragma once
#include <SDL.h>
#include "../Component.h"

#include "../Vec2.h"
class RectangleComponent : public plx::Component {
public:
    RectangleComponent() : plx::Component("RectangleComponent") {};
    void Update();
    unsigned int width = 20;
    unsigned int height = 20;
    plx::Vec2 origin;
    SDL_Color color{ 255,255,255,255 };
};