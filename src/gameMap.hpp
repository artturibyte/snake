#pragma once
#include "pixel.hpp"
#include "snake.hpp"
#include "conf.hpp"
#include <random>
#include "iostream"
#include <ncurses.h>
#include    <array>
#include    <SFML/Graphics.hpp>

const char snake_body{'X'};
const char apple_mark{'O'};
const char empty{' '};

class gameMap {
    std::array<std::array<pixel, colmax>, rowmax> matrix;
    int appleCount{0};
    
    public:
    gameMap() {}

    void update();
    void draw();
    void clear_map();
    void update_snake(snake& snk);
    void random_apple();

};