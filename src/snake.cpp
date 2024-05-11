#include "./snake.hpp"
#include "../include/SDL2/SDL.h"

Snake::Snake(SDL_Renderer *pRenderer, int cellSize) {
    (*this).pRenderer = pRenderer;
    (*this).cellSize = cellSize;
    this->direction = {1, 0};

    for (int i = 0; i < 3; i++) {
        (*this).body.push_back({6 + i, 9});
    }
}


void Snake::draw() {
    for (int i = 0; i < this->body.size(); i++) {
        SDL_Rect rect;
        rect.h = this->cellSize;
        rect.w = this->cellSize;

        rect.x = this->body[i].x * this->cellSize;
        rect.y = this->body[i].y * this->cellSize;

        SDL_RenderFillRect(pRenderer, &rect);
    }
}

void Snake::update() {
    body.pop_back();
    body.push_front({body[0].x + direction.x, body[0].y + direction.y});
}