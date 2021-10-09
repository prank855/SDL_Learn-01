#pragma once
#include <vector>
#include "Component.h"

namespace plx {
    class Node {
    public:
        void Update();
        void AddComponent(Component*);
        int GetID();
    private:
        std::vector<Component*> components;
        int id = -1;
    };
};