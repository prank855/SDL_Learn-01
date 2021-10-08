#include "Node.h"

void plx::Node::Update() {
    for (auto c : components) {
        c->Update();
    }
}