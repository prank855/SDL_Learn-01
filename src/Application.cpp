#include "Application.h"
#include "plx\plx.h"


#include <ctime>
Application::Application() {

    plx::Engine engine;

    // add systems by priority order
    auto ss = engine.AddSystem<WindowSystem>();
    ss->SetTitle("Epic Game");
    engine.AddSystem<RenderSystem>();
    engine.AddSystem<TimeSystem>();

    { // scene setup code
        plx::Scene* s = &engine.scene;
        srand((unsigned)time(NULL)); // initialize randomizer thing
        auto n = s->CreateNode();
        auto mc = n->AddComponent<MovementController>();
        auto rc = n->AddComponent<RectangleComponent>();
        n->position.x = ((double)rand() / (RAND_MAX)) * 1280;
        n->position.y = ((double)rand() / (RAND_MAX)) * 720;
    }


    engine.Start();

    //SDL_DestroyWindow(window);
    //SDL_Quit();
}