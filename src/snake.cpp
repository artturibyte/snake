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
            if (head.row - 1 < 0) {
                pos_list.push_back({rowmax, head.col});
            }
            else {
                pos_list.push_back({head.row - 1, head.col});
            }
            break;
        case down:
            if (head.row + 1 > rowmax) {
                pos_list.push_back({1, head.col});
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