#pragma once

#include "../Component.h"

class MovementController : public plx::Component {
public:
    void Init();
    void Start();
    void Update();
};