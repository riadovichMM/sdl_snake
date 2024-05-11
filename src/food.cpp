#include <random>
#include <iostream>
#include "../include/SDL2/SDL.h"
#include "./food.hpp"

Food::Food(SDL_Renderer *pRenderer, int cellSize, int cellCount) {
    (*this).pRenderer = pRenderer;
    (*this).cellSize = cellSize;
    (*this).cellCount = cellCount;
    Position position = (*this).generateRandomPosition();


    (*this).positionX = position.x;
    (*this).positionY = position.y;
}

void Food::draw() {
    SDL_Rect rect;

    rect.h = this->cellSize;
    rect.w = this->cellSize;


    rect.x = this->positionX * this->cellSize;
    rect.y = this->positionY * this->cellSize;

    SDL_RenderFillRect((*this).pRenderer, &rect);
}

int Food::generateRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

Position Food::generateRandomPosition() {
    int x = generateRandomNumber(0, this->cellCount);
    int y = generateRandomNumber(0, this->cellCount);

    return Position{x, y};
}
