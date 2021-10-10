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

        //update scene
        scene.Update();

        //late update systems
        for (auto s : systems) {
            s->LateUpdate();
        }
    }

    std::cout << "Engine Stopped\n";
}