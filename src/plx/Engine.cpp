#include <iostream>
#include "Engine.h"
#include "System.h"
#include "systems/TimeSystem.h"

plx::Engine* plx::Engine::self = nullptr;

plx::Engine::Engine() {
    plx::Engine::self = this;
}

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
        for (auto sys : systems) {
            sys->Update();
        }

        //update scene
        scene.Update();

        //late update systems
        for (auto sys : systems) {
            sys->LateUpdate();
        }
    }

    std::cout << "Engine Stopped\n";
}