#pragma once
#include "pixel.h"
#include "snake.h"

const int rowmax = 33;
const int colmax = 100;

const char snake_body{'X'};
const char empty{' '};

class gameMap {

    pixel matrix[rowmax][colmax];
    public:
    gameMap() {}

    void update();

    void draw();

    void update_snake(snake snk);

};