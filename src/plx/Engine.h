#pragma once

#include <vector>
#include <iostream>
#include "Scene.h"

namespace plx {
    class System;
    class Engine {
    public:
        static Engine* self;
        Engine();
        ~Engine();
        Scene scene;
        unsigned int frame = 0;
        bool isRunning = true;

        void Start();

        template<typename T>
        T* GetSystem() {
            T sys;
            for (auto s : systems) {
                if (s->name == sys.name) {
                    return (T*)s;
                }
            }
            return nullptr;
        };
        template<typename T>
        T* AddSystem() {
            T* t = new T;
            systems.push_back(t);

            t->engine = this;
            t->Init();
            std::cout << "Added + Initialized System: " << t->name << std::endl;

            return t;
        };
    private:
        std::vector<System*> systems;
        void BeginEngineLoop();
    };
};