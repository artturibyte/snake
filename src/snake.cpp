#include "snake.hpp"
#include "conf.hpp"

void snake::move_snake() {
        snake_part head = pos_list.back();
        switch (dir)
        {
        case right:
            if (head.col + 1 > colmax - 1) {
                pos_list.push_back({head.row, 0});
            }
            else {
                pos_list.push_back({head.row, head.col + 1});
            }
            break;
        case left:
            if (head.col <= 0) {
                pos_list.push_back({head.row, colmax - 1});
            }
            else
            {
                pos_list.push_back({head.row, head.col - 1});
            }
            break;
        case up:
            if (head.row == 0) {
                pos_list.push_back({rowmax -1, head.col});
            }
            else {
                pos_list.push_back({head.row - 1, head.col});
            }
            break;
        case down:
            if (head.row >= rowmax - 1) {
                pos_list.push_back({0, head.col});
            }
            else {
                pos_list.push_back({head.row + 1, head.col});
            }
            break;
        default:
            break;
        }
        pos_list.pop_front();
}

void snake::extend_snake() {
    snake_part tail = pos_list.front();
    pos_list.push_front({tail.row - 1, tail.col - 1});
}