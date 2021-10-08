#pragma once

#include <vector>
#include "Scene.h"

namespace plx {
    class System;
    class Engine {
    public:
        Scene scene;
        int frame = 0;
        bool isRunning = true;
        void Start();
        void AddSystem(System*);
    private:
        std::vector<System*> systems;
        void BeginGameLoop();
    };
};