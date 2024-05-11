#pragma once
#include "../include/SDL2/SDL.h"

struct Position {
    int x;
    int y;
};

class Food {
    private:
        int positionX;
        int positionY;
        int cellSize;
        int cellCount;
        SDL_Renderer *pRenderer;
    public:
        Food(SDL_Renderer *pRenderer, int cellSize, int cellCount);
        void draw();
        Position generateRandomPosition();
        int generateRandomNumber(int min, int max);
};