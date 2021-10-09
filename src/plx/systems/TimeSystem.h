#pragma once
#include "../System.h"
#include <chrono>
class TimeSystem : public plx::System {
public:
    static float deltaTime;
    std::string name = "TimeSystem";
    void Init();
    void Start();
    void Update();
private:
    std::chrono::_V2::system_clock::time_point startTime = std::chrono::high_resolution_clock::now();;
    float lastTime = 0;
    float getElapsed();
};
