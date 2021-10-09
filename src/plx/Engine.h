#pragma once

#include <vector>
#include <iostream>
#include "Scene.h"

namespace plx {
    class System;
    class Engine {
    public:
        Scene scene;
        int frame = 0;
        bool isRunning = true;
        void Start();

        template<typename T>
        T* GetSystem() {
            for (auto s : systems) {
                if (static_cast<T*>(s) != nullptr) {
                    return static_cast<T*>(s);
                }
            }
            return nullptr;
        };

        template<typename T>
        T* AddSys() {
            T* s = new T;

            std::cout << "Added + Initialized System: " << s->name << std::endl;
            systems.push_back(s);
            s->engine = this;
            s->Init();

            return s;
        };

    private:
        std::vector<System*> systems;
        void BeginEngineLoop();
    };
};