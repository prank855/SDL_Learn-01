#include "Scene.h"

void plx::Scene::Update() {
    for (auto n : nodes) {
        n->Update();
    }
}