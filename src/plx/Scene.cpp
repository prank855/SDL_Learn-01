#include "Scene.h"
#include <iostream>

plx::Node* plx::Scene::CreateNode() {
    Node* n = new Node;
    n->id = nodeCount++;
    nodes.push_back(n);
    std::cout << "Added Node with ID " << n->id << " to scene\n";
    return n;
}

void plx::Scene::Update() {
    for (auto n : nodes) {
        n->Update();
    }
}