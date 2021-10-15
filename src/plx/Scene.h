#pragma once
#include <vector>
#include "Node.h"
namespace plx {
    class Scene {
    public:
        Scene();
        ~Scene();
        void Update();
        Node* CreateNode();
        const unsigned int poolInitialSize = 5000;
    private:
        unsigned int nodeCount = 0;
        std::vector<Node*> nodes;
        std::vector<Node*> nodePool;
    };
};