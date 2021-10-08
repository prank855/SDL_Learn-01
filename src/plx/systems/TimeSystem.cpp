#include <iostream>
#include "TimeSystem.h"
#include "../Engine.h"

float plx::systems::TimeSystem::deltaTime = 0;

void plx::systems::TimeSystem::Init() {
    auto now = getElapsed();
    deltaTime = now - lastTime;
    lastTime = now;
}

float plx::systems::TimeSystem::getElapsed() {
    std::chrono::duration<float>  now = std::chrono::high_resolution_clock::now() - startTime;
    return now.count();
}

void plx::systems::TimeSystem::Start() {

}

void plx::systems::TimeSystem::Update() {
    auto now = getElapsed();
    deltaTime = now - lastTime;
    lastTime = now;
}