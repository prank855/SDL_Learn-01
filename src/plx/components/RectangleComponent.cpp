#include "RectangleComponent.h"
#include "../Engine.h"
#include "../systems/RenderSystem.h"
#include "../systems/RectangleGraphic.h"


#include <iostream>
void RectangleComponent::Update() {
    auto e = plx::Engine::self;
    if (e != nullptr) {
        auto rs = e->GetSystem<RenderSystem>();
        auto recGraphic = new RectangleGraphic;
        recGraphic->position = parent->position;
        rs->AddGraphic(recGraphic);
    }
}