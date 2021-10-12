#pragma once
#include <vector>
#include "Node.h"
namespace plx {
    class Scene {
    public:
        void Update();
        Node* CreateNode();
    private:
        unsigned int nodeCount = 0;
        std::vector<Node*> nodes;
    };
};