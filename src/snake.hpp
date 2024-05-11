#pragma once


#include <deque>
#include "../include/SDL2/SDL.h"


struct SnakePosition {
    int x;
    int y;
};

struct Direction {
    int x;
    int y;
};

class Snake {
    private:
        std::deque<SnakePosition> body;
        SDL_Renderer *pRenderer;
        int cellSize;


    public:
        Direction direction;
        Snake(SDL_Renderer *pRenderer, int cellSize);
        void draw();
        void update();
};
