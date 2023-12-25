#include "gameMap.hpp"
#include "iostream"
#include <ncurses.h>
//size

//update

void gameMap::draw() {
    erase();

    for (int row = 0; row < rowmax; ++row) {
        for (int column = 0; column < colmax; ++column) {
            char state = (matrix[row][column].state ? snake_body : empty);
            mvaddch(row,column, state);
             
        }
    }
}

void gameMap::clear_map() {
    for (int row = 0; row < rowmax; ++row) {
        for (int column = 0; column < colmax; ++column) {
            matrix[row][column].state = false;
        }
    }
}

void gameMap::update_snake(snake snake) {
    
    gameMap::clear_map();

    for (auto el: snake.pos_list)    // Use a range-for loop
        matrix[el.row][el.col].contains_snake();
}

