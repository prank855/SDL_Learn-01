#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Component.h"
#include "Vec2.h"
namespace plx {
    class Scene;
    class Node {
    public:
        void Update();
        Vec2 position;
        Vec2 GetPosition();
        std::string name = "Unnamed Node";
        const unsigned int& id = m_id;
        Node* AddChild();
        template<typename T> T* AddComponent() {
            T* t = new T;
            Component* com = t;
            components.push_back(com);
            com->parent = this;
            com->Init();
            return t;
        };
    private:
        Node() {};
        friend class Scene;
        Scene* scene;
        Node* parent = nullptr;
        unsigned int m_id;
        bool kill = false;
        std::vector<Component*> components;
        std::vector<Node*> children;
    };
};