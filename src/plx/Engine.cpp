#include <iostream>

#include "Engine.h"
#include "System.h"

void plx::Engine::AddSystem(System* s) {
    std::cout << "Added + Initialized System: " << s->name << std::endl;
    systems.push_back(s);
    s->engine = this;
    s->Init();
}

#include "systems/TimeSystem.h"
void plx::Engine::Start() {
    std::cout << "Engine Started\n";

    //start all systems
    for (auto s : systems) {
        s->Start();
    }

    BeginEngineLoop();
}

void plx::Engine::BeginEngineLoop() {
    while (isRunning) {
        //increment frame count
        frame++;

        //update all systems
        for (auto s : systems) {
            s->Update();
        }

        //update all scene nodes
        scene.Update();

        //if TimeSystem::deltaTime exists, output frametime info
        if (plx::systems::TimeSystem::deltaTime) {
            using namespace plx::systems;
            std::cout << TimeSystem::deltaTime * 1000 << "ms \n";
        }

        for (auto s : systems) {
            s->LateUpdate();
        }

        //kill game loop after 300 frames
        if (frame >= 60 * 5) {
            isRunning = false;
        }
    }
    std::cout << "Engine Stopped\n";
}