#pragma once
#include <string>

namespace plx {
    class Engine;
    class System {
    public:
        Engine* engine = nullptr;
        const char* name;
        bool debug = false;
        System(const char*);
        void virtual Init() {};
        void virtual Start() {};
        void virtual Update() {};
        void virtual LateUpdate() {};
    };
};