#include "App.h"
#include <SDL_events.h>
#include <SDL_pixels.h>
#include <SDL_render.h>

bound::App::App(std::string name, int width, int height){
    mWindow = SDL_CreateWindow(name.c_str(),SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    mRenderer = SDL_CreateRenderer(mWindow, -1, 0);

    // delta time
    Uint64 ticks_per_second = SDL_GetPerformanceFrequency();
    Uint64 frame_start;
    Uint64 frame_finish;
    frame_start = SDL_GetPerformanceCounter();
    float deltaTime = 0;

    while(bActivate){
        MainLoop(deltaTime);

        frame_finish = SDL_GetPerformanceCounter();
        deltaTime = (float)(frame_finish - frame_start) / (float)ticks_per_second;
        frame_start = frame_finish;

        SDL_RenderPresent(mRenderer);
    }
}

bound::App::~App(){
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
}


void bound::App::MainLoop(float deltaTime){
    SDL_Event event;
    SDL_WaitEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            bActivate = true;
            break;
    }
}

SDL_Renderer* bound::App::GetRenderer() const{
    return mRenderer;
}