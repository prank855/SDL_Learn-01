#include <iostream>
#include "TimeSystem.h"
#include "../Engine.h"

float TimeSystem::deltaTime = 0;

// returns how long engine has been running
float TimeSystem::elapsed = 0;

void TimeSystem::Init() {
    auto now = getElapsed();
    deltaTime = now - lastTime;
    lastTime = now;
}

void TimeSystem::Start() {}

// returns time since program start
float TimeSystem::getElapsed() {
    return ((std::chrono::duration<float>)(std::chrono::high_resolution_clock::now() - startTime)).count();
}

void TimeSystem::Update() {
    auto now = getElapsed();
    deltaTime = now - lastTime;
    lastTime = now;
    elapsed += deltaTime;
}