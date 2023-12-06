#include "snake.h"

void snake::move_snake() {
        snake_part head = pos_list.back();
        switch (dir)
        {
        case right:
            pos_list.push_back({head.row, head.col + 1});
            break;
        case left:
            pos_list.push_back({head.row, head.col - 1});
            break;
        case up:
            pos_list.push_back({head.row - 1, head.col});
            break;
        case down:
            pos_list.push_back({head.row + 1, head.col});
            break;
        default:
            break;
        }
        pos_list.pop_front();
        
}