#include "Scene.h"
#include "Node.h"

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

plx::Node* plx::Scene::MakeNode() {
    if (nodePool.size() <= 0) {
        auto n = new Node;
        n->m_id = nodeCount++;
        return n;
    }
    Node* n = nodePool.back();
    n->m_id = nodeCount++;
    nodePool.pop_back();
    std::cout << "CREATING NODE " << n->id << std::endl;
    return n;
}

plx::Node* plx::Scene::CreateNode() {
    auto temp = MakeNode();
    temp->scene = this;
    temp->name = "Node " + std::to_string(temp->id);
    nodes.push_back(temp);
    nodePool.pop_back();
    std::cout << "ADDED NODE " << temp->id << " TO SCENE\n";
    return temp;
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