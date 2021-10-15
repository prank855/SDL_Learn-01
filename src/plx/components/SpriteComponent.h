#pragma once
#include <SDL.h>
#include "../Component.h"


#include "../Engine.h"
#include "../systems/RenderSystem.h"
#include "../systems/SpriteGraphic.h"

#include <string>

class SpriteComponent : public plx::Component {
public:
    SpriteComponent() : plx::Component("SpriteComponent") {};
    float width = 20;
    float height = 20;
    std::string fileName;
    void Update();
};