#include "gameMap.h"
#include "iostream"
#include <ncurses.h>
//size

//update

void gameMap::draw() {
    // ANSI control command
    // \x1b means "escape"
    // Escape[2J clears the screen and returns the cursor to the "home" position
    clear();

    for (int row = 0; row < rowmax; ++row) {
        for (int column = 0; column < colmax; ++column) {
            char state = (matrix[row][column].state ? snake_body : empty);
            mvaddch(row,column, state);
             
        }
    }
}

void gameMap::update_snake(snake snake) {
    for (int row = 0; row < rowmax; ++row) {
        for (int column = 0; column < colmax; ++column) {
            matrix[row][column].state = false;
        }
    }
    for (auto el: snake.pos_list)    // Use a range-for loop
        matrix[el.row][el.col].contains_snake();
}

