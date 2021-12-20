#include <SDL.h>
#include <cstdio>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Bullet Storm", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 2;
    }

    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

    SDL_Surface* etiSurface = SDL_LoadBMP("./../resources/eti.bmp");
    if (etiSurface == nullptr) {
        printf("Unable to load image %s! SDL Error: %s\n", "./../resources/eti.bmp", SDL_GetError());
        return 3;
    }

    SDL_BlitSurface(etiSurface,nullptr,screenSurface,nullptr);
    SDL_UpdateWindowSurface(window);


    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }


    SDL_FreeSurface(etiSurface);
    SDL_FreeSurface(screenSurface);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
