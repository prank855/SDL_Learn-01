#pragma once
#include <vector>
#include <iostream>
#include "Component.h"
#include "Vec2.h"
#include "Scene.h"
namespace plx {
    class Node {
    public:
        void Update();
        Vec2 position;
        int GetID() {
            return id;
        }
        template<typename T>
        T* AddComponent() {
            T* t = new T;

            Component* com = t;
            components.push_back(com);

            com->parent = this;
            com->Init();

            //std::cout << "Component " << com->name << " added to Node " << id << std::endl;

            return t;
        }
    private:
        Node() {};
        friend class Scene;
        unsigned int id;
        bool kill = false;
        std::vector<Component*> components;
    };
};