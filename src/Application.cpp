#include "Application.h"
#include "plx\plx.h"
#include <ctime>
#include <thread>

Application::Application() {

    plx::Engine engine;

    // add systems by priority order

    auto ws = engine.AddSystem<WindowSystem>();
    ws->SetTitle("Epic Game");
    engine.AddSystem<RenderSystem>();
    engine.AddSystem<TimeSystem>();

    { // scene setup code
        plx::Scene* s = &engine.scene; // pointer to scene

        srand((unsigned)time(NULL)); // initialize randomizer thing

        auto n = s->CreateNode(); // create node

        auto mc = n->AddComponent<MovementController>();
        mc->speed = 150;

        /*
        auto rc = n->AddComponent<RectangleComponent>();
        rc->width = 25;
        rc->height = 25;
        rc->color.r = 0;rc->color.g = 128; rc->color.b = 255;
        */

        auto spritec = n->AddComponent<SpriteComponent>();
        spritec->width = 100;
        spritec->height = 100;
        spritec->fileName = "./resources/steel.bmp";

        // set node position to a random position on screen
        n->position.x = rand() % ws->windowed_width;
        n->position.y = rand() % ws->windowed_height;

    }


    engine.Start();

    //SDL_DestroyWindow(window);
    //SDL_Quit();
}