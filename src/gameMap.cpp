#include "gameMap.hpp"

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

void gameMap::update_snake(snake& sk) {
    
    gameMap::clear_map();
 
    if (matrix[sk.pos_list.back().row][sk.pos_list.back().col].apple) {
        sk.extend_snake();
        matrix[sk.pos_list.back().row][sk.pos_list.back().col].contains_apple(false);
        appleCount = appleCount - 1;
        random_apple();
    }

    for (auto el: sk.pos_list)    // Use a range-for loop
        matrix[el.row][el.col].contains_snake();
}


void gameMap::random_apple() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> rowDist(1, rowmax);
    std::uniform_int_distribution<int> colDist(1, colmax);
    if (appleCount < 1) {
        matrix[rowDist(mt)][colDist(mt)].contains_apple(true);
        appleCount += 1;
    }
}