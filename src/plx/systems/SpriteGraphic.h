#pragma once

#include "Graphic.h"

#include "../Vec2.h"

#include <iostream>

#include <SDL_image.h>

#include <map>

#include <string>

class SpriteGraphic : public Graphic {
public:
    plx::Vec2 position;
    float width;
    float height;
    std::string fileName = "";
private:
    void Render(SDL_Renderer* renderer);
    static std::map<std::string, SDL_Texture*> dictionary;
};
