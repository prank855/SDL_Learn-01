#pragma once

namespace plx {
    class Node;
    class Component {
    public:
        void virtual Init();
        void virtual Start();
        void virtual Update();
        Node* parent;
    };
};