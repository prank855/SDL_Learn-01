#include <iostream>
#include "TimeSystem.h"
#include "../Engine.h"

float TimeSystem::deltaTime = 0;

// returns time since engine start
float TimeSystem::elapsed = 0;

void TimeSystem::Init() {
    auto now = getElapsed();
    deltaTime = now - lastTime;
    lastTime = now;
}

void TimeSystem::Start() {}

// returns time since program start
float TimeSystem::getElapsed() {
    std::chrono::duration<float> now = std::chrono::high_resolution_clock::now() - startTime;
    return now.count();
}

void TimeSystem::Update() {
    auto now = getElapsed();
    deltaTime = now - lastTime;
    lastTime = now;
    elapsed += deltaTime;
}