#include "SpriteComponent.h"
#include "../Engine.h"
#include "../systems/RenderSystem.h"
#include "../systems/SpriteGraphic.h"

void SpriteComponent::Update() {
    auto e = plx::Engine::self;
    if (e != nullptr) {
        auto rs = e->GetSystem<RenderSystem>();
        auto sprGraphic = new SpriteGraphic;
        sprGraphic->position = parent->position;
        sprGraphic->fileName = fileName;
        sprGraphic->width = width;
        sprGraphic->height = height;
        rs->AddGraphic(sprGraphic);
    }
}