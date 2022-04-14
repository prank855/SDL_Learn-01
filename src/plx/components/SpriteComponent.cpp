#include "SpriteComponent.h"
#include "../Engine.h"
#include "../systems/RenderSystem.h"
#include "../systems/SpriteGraphic.h"
#include "../Node.h"
void SpriteComponent::Update() {
    auto engine = plx::Engine::self;
    if (engine != nullptr) {
        auto renderSystem = engine->GetSystem<RenderSystem>();
        auto spriteGraphic = new SpriteGraphic;
        spriteGraphic->position = parent->position;
        spriteGraphic->position.x -= origin.x * width;
        spriteGraphic->position.y -= origin.y * height;
        spriteGraphic->fileName = fileName;
        spriteGraphic->width = width;
        spriteGraphic->height = height;
        renderSystem->AddGraphic(spriteGraphic);
    }
}