#include "Application.h"

#include "plx\systems\TimeSystem.h"
#include "plx\systems\WindowSystem.h"
#include "plx/systems/RenderSystem.h"
#include "plx\Engine.h"

Application::Application() {

    plx::Engine engine;
    // add systems by priority order
    auto ss = engine.AddSystem<WindowSystem>();
    ss->SetTitle("Epic Game");
    engine.AddSystem<RenderSystem>();
    engine.AddSystem<TimeSystem>();

    //engine.scene.AddNode(new plx::Node);

    engine.Start();

    //SDL_DestroyWindow(window);
    //SDL_Quit();
}