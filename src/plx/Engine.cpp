#include <iostream>
#include "Engine.h"
#include "System.h"
#include "systems/TimeSystem.h"

plx::Engine* plx::Engine::self = nullptr;

plx::Engine::Engine() {
    plx::Engine::self = this;
}

plx::Engine::~Engine() {
    for (auto s : systems) {
        delete s;
    }
    systems.clear();
}

void plx::Engine::Start() {
    std::cout << "Engine Started\n";

    //start all systems
    for (auto s : systems) {
        s->Start();
    }

    BeginEngineLoop();
}

float timeSinceFps = 0;
int framesSinceFps = 0;
float fpsDebugTimerLength = 2.0f;
void plx::Engine::BeginEngineLoop() {

    while (isRunning) {
        frame++;

        timeSinceFps += TimeSystem::deltaTime;
        framesSinceFps++;
        if (timeSinceFps > fpsDebugTimerLength) {
            timeSinceFps -= 2;
            std::cout << "FPS: " << (float)framesSinceFps / fpsDebugTimerLength << "\n";
            framesSinceFps = 0;
        }

        for (auto sys : systems) {
            sys->Update();
        }

        scene.Update();

        for (auto sys : systems) {
            sys->LateUpdate();
        }
    }
    std::cout << "Engine Stopped\n";
}