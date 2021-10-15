#include "Scene.h"
#include <iostream>

#include <chrono>

#include <iomanip>
plx::Scene::Scene() {
    auto t1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < poolInitialSize; i++) {
        auto n = new Node;
        nodePool.push_back(n);
    }

    auto t2 = std::chrono::high_resolution_clock::now();

    auto t = ((std::chrono::duration<float>)(t2 - t1)).count();

    std::cout << "Created " << poolInitialSize << " pooled nodes in " <<
        t * 1000.0f << "ms\n";
}

plx::Scene::~Scene() {
    for (auto n : nodes) {
        delete n;
    }
    nodes.clear();

    for (auto n : nodePool) {
        delete n;
    }
    nodePool.clear();

}

plx::Node* plx::Scene::CreateNode() {
    if (nodePool.size() <= 0) {
        auto n = new Node;
        n->id = nodeCount++;
        //std::cout << "Node pool depleted\n";
        return n;
    }
    Node* n = nodePool.back();
    n->id = nodeCount++;
    nodes.push_back(n);
    nodePool.pop_back();
    return n;
}

void plx::Scene::Update() {
    for (auto n : nodes) {
        if (!n->kill) {
            n->Update();
        } else {
            // delete node
            // free components
            // add back to pool
        }

    }
}