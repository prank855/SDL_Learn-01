#pragma once
#include <SDL.h>
#include "../Component.h"

class RectangleComponent : public plx::Component {
public:
    RectangleComponent() : plx::Component("RectangleComponent") {};
    void Update();
};