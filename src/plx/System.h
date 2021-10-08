#pragma once
#include <string>

namespace plx {
    class Engine;
    class System {
    public:
        std::string name = "Unnamed System";
        Engine* engine = NULL;
        bool debug = false;
        void virtual Init() {};
        void virtual Start() {};
        void virtual Update() {};
    };
};