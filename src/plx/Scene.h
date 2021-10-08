#pragma once
#include <vector>
#include "Node.h"

namespace plx {
    class Scene {
    public:
        void AddNode(Node*);
        void Update();
    private:
        std::vector<Node*> nodes;
    };
};