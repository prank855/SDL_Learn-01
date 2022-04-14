#pragma once
#include <vector>
namespace plx {
    class Node;
    class Scene {
    public:
        Scene();
        ~Scene();
        void Update();
        Node* CreateNode();
        const unsigned int poolInitialSize = 5000;
    private:
        friend class Node;
        Node* MakeNode();
        unsigned int nodeCount = 0;
        std::vector<Node*> nodes;
        std::vector<Node*> nodePool;
    };
};