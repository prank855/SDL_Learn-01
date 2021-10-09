#include "Application.h"

//#include <SDL.h>
//#include <SDL_image.h>

#include "plx\systems\TimeSystem.h"
#include "plx\Engine.h"

Application::Application() {
    //SDL_Window* window = NULL;
    //SDL_Renderer* renderer;

    //SDL_Init(SDL_INIT_VIDEO);
    //IMG_Init(IMG_INIT_PNG);

    //window = SDL_CreateWindow("SDL Learning", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
    //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    plx::Engine engine;
    auto* ts = new TimeSystem;
    //ts->debug = true;
    engine.AddSystem(ts);
    engine.Start();

    //SDL_DestroyWindow(window);
    //SDL_Quit();
}