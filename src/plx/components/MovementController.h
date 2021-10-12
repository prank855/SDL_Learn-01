#pragma once

#include "../Component.h"

class MovementController : public plx::Component {
public:
    MovementController() : plx::Component("MovementController") {};
    void Init();
    void Update();
    float speed = 80;
};