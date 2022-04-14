#include "RectangleComponent.h"
#include "../Engine.h"
#include "../systems/RenderSystem.h"
#include "../systems/RectangleGraphic.h"


#include <iostream>
#include "../Node.h"
void RectangleComponent::Update() {
    auto e = plx::Engine::self;
    if (e != nullptr) {
        auto renderSystem = e->GetSystem<RenderSystem>();
        auto rectGraphic = new RectangleGraphic;
        rectGraphic->width = width;
        rectGraphic->height = height;
        rectGraphic->position = parent->GetPosition();
        rectGraphic->position.x -= origin.x * width;
        rectGraphic->position.y -= origin.y * height;
        rectGraphic->color = color;
        renderSystem->AddGraphic(rectGraphic);
    }
}