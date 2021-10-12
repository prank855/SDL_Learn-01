#include "Application.h"

#include "plx\systems\TimeSystem.h"
#include "plx\systems\WindowSystem.h"
#include "plx/systems/RenderSystem.h"
#include "plx\Engine.h"
#include "plx\components\MovementController.h"
#include "plx\components\RectangleComponent.h"

Application::Application() {

    plx::Engine engine;

    // add systems by priority order
    auto ss = engine.AddSystem<WindowSystem>();
    ss->SetTitle("Epic Game");
    engine.AddSystem<RenderSystem>();
    engine.AddSystem<TimeSystem>();

    plx::Scene* s = &engine.scene;

    auto n = s->CreateNode();
    auto mc = n->AddComponent<MovementController>();
    auto rc = n->AddComponent<RectangleComponent>();

    engine.Start();

    //SDL_DestroyWindow(window);
    //SDL_Quit();
}