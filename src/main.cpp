#include <iostream>
#include "../include/SDL2/SDL.h"
#include "./food.hpp"
#include "./snake.hpp"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int CELL_SIZE = 20;
const int CELL_COUNT = 30;



int main() {
    int window_width_height = CELL_SIZE * CELL_COUNT;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "sdl init error" << std::endl;
        return 1;
    }

    SDL_Window* pWindow = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width_height, window_width_height, SDL_WINDOW_SHOWN);

    if (pWindow == NULL) {
        std::cout << "window create error" << std::endl;
        return 1;
    }

    SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);



    // create food object
    Food food = Food(pRenderer, CELL_SIZE, CELL_COUNT);
    Snake snake = Snake(pRenderer, CELL_SIZE);


    int fps = 10;

    int desireDelta = 1000 / fps;
    bool run = true;
    SDL_Event e;

    while (run) {
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                run = false;
            }


            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_s) {
                    snake.direction = {0, 1};
                }
                if (e.key.keysym.sym == SDLK_d) {
                    snake.direction = {1, 0};
                }
                if (e.key.keysym.sym == SDLK_w) {
                    snake.direction = {0, -1};
                }
                if (e.key.keysym.sym == SDLK_a) {
                    snake.direction = {-1, 0};
                }
            }
        }

        snake.update();

        Uint32 start = SDL_GetTicks();

        SDL_SetRenderDrawColor(pRenderer, 173, 204, 96, 0);
        SDL_RenderClear(pRenderer);
        SDL_SetRenderDrawColor(pRenderer, 43, 51, 24, 0);


        food.draw();
        snake.draw();

        SDL_RenderPresent(pRenderer);

        Uint32 delta = SDL_GetTicks() - start;

        if (delta < desireDelta) {
            SDL_Delay(desireDelta - delta);
        }
    }

    SDL_DestroyWindow(pWindow);
    SDL_Quit();

    pWindow = nullptr;

    return 0;
}