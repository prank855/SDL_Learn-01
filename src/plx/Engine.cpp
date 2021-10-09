#include <iostream>
#include "Engine.h"
#include "System.h"
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
        if (TimeSystem::deltaTime) {
            //std::cout << TimeSystem::deltaTime * 1000 << "ms \n";
        }

        //late update systems
        for (auto s : systems) {
            s->LateUpdate();
        }

    }
    std::cout << "Engine Stopped\n";
}