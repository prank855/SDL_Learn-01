#pragma once
#include <vector>
#include "Component.h"

namespace plx {
    class Node {
    public:
        void Update();
        void AddComponent(Component*);
    private:
        std::vector<Component*> components;
    };
};