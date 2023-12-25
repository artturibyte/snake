#pragma once
#include "pixel.hpp"
#include "snake.hpp"
#include "conf.hpp"

const char snake_body{'X'};
const char empty{' '};

class gameMap {

    pixel matrix[rowmax][colmax];
    public:
    gameMap() {}

    void update();

    void draw();

    void clear_map();

    void update_snake(snake snk);

};