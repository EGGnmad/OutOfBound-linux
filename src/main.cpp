#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>

using namespace std;

struct Pos{
    int x, y;
};

int main(){
    SDL_Init(0);

    SDL_Window* window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
    SDL_Surface* canvas = SDL_GetWindowSurface(window);

    bool isRunning = true;

    while(isRunning){
        memset(canvas->pixels, 255, 1280*720*4);
        
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch (event.type) {
                case SDL_QUIT:
                    isRunning = false;
            }

        }
        
        SDL_UpdateWindowSurface(window);
    }

    return 0;
}
