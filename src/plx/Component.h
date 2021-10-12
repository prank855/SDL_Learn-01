#pragma once

namespace plx {
    class Node;
    class Component {
    public:
        Component(const char*);
        const char* name;
        void virtual Init() {};
        void virtual Start() {};
        void virtual Update() {};
        Node* parent;
    };
};