#pragma once
#include <vector>
#include <iostream>
#include "Component.h"
#include "Vec2.h"

namespace plx {
    class Node {
    public:
        void Update();
        int id = -1;
        Vec2 position;
        template<typename T>
        T* AddComponent() {
            T* t = new T;

            Component* com = t;
            components.push_back(com);

            com->parent = this;
            com->Init();

            std::cout << "Component " << com->name << " added to Node " << id << std::endl;

            return t;
        }
    private:
        std::vector<Component*> components;
    };
};