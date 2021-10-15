#pragma once

#include <SDL.h>

class Graphic {
private:
    void virtual Render(SDL_Renderer*) {};
    friend class RenderSystem;
};