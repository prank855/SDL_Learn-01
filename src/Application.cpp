#include "Application.h"
#include "plx\plx.h"
#include <ctime>

Application::Application() {

    plx::Engine engine;

    // add systems by priority order

    auto ws = engine.AddSystem<WindowSystem>();
    ws->SetTitle("Epic Game");
    engine.AddSystem<RenderSystem>();
    engine.AddSystem<TimeSystem>();

    { // scene setup code
        plx::Scene* s = &engine.scene; // pointer to scene

        auto tempNode = s->CreateNode(); // create node

        auto mc = tempNode->AddComponent<MovementController>();
        mc->speed = 150;

        auto rectangleComponent = tempNode->AddComponent<RectangleComponent>();
        auto spriteComponent = tempNode->AddComponent<SpriteComponent>();

        rectangleComponent->origin = { .5,.5 };
        rectangleComponent->width = 110;
        rectangleComponent->height = 110;
        rectangleComponent->color = SDL_Color{ 255,0,0,255 };

        spriteComponent->width = 100;
        spriteComponent->height = 100;
        spriteComponent->origin = { .5,.5 };
        spriteComponent->fileName = "./resources/steel.bmp";

        // set node position to a random position on screen
        srand((unsigned)time(NULL)); // initialize randomizer thing
        tempNode->position.x = rand() % ws->windowed_width;
        tempNode->position.y = rand() % ws->windowed_height;

    }

    engine.Start();
}