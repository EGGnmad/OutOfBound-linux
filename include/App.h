#pragma once


#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include <SDL_events.h>
#include <iostream>
#include <string>

#include "bound.h"

class bound::App{
protected:
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;

    bool bActivate = true;
public:
    App(std::string name, int width, int height);
    ~App();

    virtual void MainLoop(float deltaTime);

    SDL_Renderer* GetRenderer() const;
};