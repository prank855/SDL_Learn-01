#pragma once
#include <SDL.h>
#include "../Component.h"


#include "../Engine.h"
#include "../systems/RenderSystem.h"
#include "../systems/SpriteGraphic.h"

#include <string>
#include "../Vec2.h"
class SpriteComponent : public plx::Component {
public:
    SpriteComponent() : plx::Component("SpriteComponent") {};
    float width = 20;
    float height = 20;
    plx::Vec2 origin;
    std::string fileName;
    void Update();
};