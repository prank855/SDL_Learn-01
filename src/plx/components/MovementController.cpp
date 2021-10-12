#include <SDL.h>
#include <iostream>
#include "MovementController.h"
#include "../Node.h"
#include "../systems/TimeSystem.h"

void MovementController::Init() {
    parent->position.y = 720 / 2;
    parent->position.x = 1280 / 2;
}

void MovementController::Update() {
    const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);
    if (keyboard_state_array[SDL_SCANCODE_W]) {
        parent->position.y += -1 * TimeSystem::deltaTime * speed;
    }
    if (keyboard_state_array[SDL_SCANCODE_A]) {
        parent->position.x += -1 * TimeSystem::deltaTime * speed;
    }
    if (keyboard_state_array[SDL_SCANCODE_S]) {
        parent->position.y += 1 * TimeSystem::deltaTime * speed;
    }
    if (keyboard_state_array[SDL_SCANCODE_D]) {
        parent->position.x += 1 * TimeSystem::deltaTime * speed;
    }
}