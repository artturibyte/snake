#include "gameMap.hpp"
#include "iostream"
#include <ncurses.h>
//size

//update

void gameMap::draw() {
    erase();

    for (int row = 0; row < rowmax; ++row) {
        for (int column = 0; column < colmax; ++column) {
            char state = (matrix[row][column].snake ? snake_body : empty);
            if (matrix[row][column].apple) {state = apple_mark; };
            mvaddch(row,column, state);
        }
    }
}

void gameMap::clear_map() {
    for (int row = 0; row < rowmax; ++row) {
        for (int column = 0; column < colmax; ++column) {
            matrix[row][column].snake = false;
        }
    }
}

void gameMap::update_snake(snake& snake) {
    
    gameMap::clear_map();

    if (matrix[snake.pos_list.back().row][snake.pos_list.back().col].apple) {
        snake.extend_snake();
    }

    for (auto el: snake.pos_list)    // Use a range-for loop
        matrix[el.row][el.col].contains_snake();
}


void gameMap::set_apple(int x, int y) {
    matrix[x][y].contains_apple();
}