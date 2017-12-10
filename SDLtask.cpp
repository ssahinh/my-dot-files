/*
Compile command:
g++ -o test main.cpp -lSDLmain -lSDL -lGL
 */
 
#include <SDL2/SDL.h>
#include <iostream>

// screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

// initialize sdl
bool init()
{
    // result of initialization
    bool success = true;
    
    // Intialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! error: " << SDL_GetError() << "\n";
        success = false;
    }
    else {
        // create window
        gWindow = SDL_CreateWindow("SDL Skeleton", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            std::cout << "Window could not be created! error: " << SDL_GetError() << "\n";
            success =false;
        }
        else {
            // create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL) {
                std::cout << "Renderer could not be created. error: " << SDL_GetError() << "\n";
                success =false;
            }
            else {
                SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff);
            }
        }
    }
    
    return success;
}

void close()
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gRenderer = NULL;
    gWindow = NULL;

    SDL_Quit();
}

int main(int argc, const char* argv[])
{
    if (!init()) {
        std::cout << "Failed to initialize!\n";
    }
    else {
        bool quit = false;

        SDL_Event e;

        while (!quit) {
           // handle event on queue
           while (SDL_PollEvent(&e) != 0) {
               // user request to quit
               if (e.type == SDL_QUIT) {
                   quit = true;
               }

               // clear screen
               SDL_RenderClear(gRenderer);

               // update screen
               SDL_RenderPresent(gRenderer);
           }
        }
    }
    
    close();
    
    return 0;
}
