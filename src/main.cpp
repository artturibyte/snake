#include "gameMap.hpp"
#include <iostream>
#include <ncurses.h>
#include <chrono>
#include <thread>

void check_key_press(snake &snak) {
    int ch;
    switch((ch=getch())) {
        case KEY_UP:
            //printw("Up") ; //key up
            snak.change_dir(direction::up);
            break;
        case KEY_DOWN:
            //printw("Down")  ;   // key down
            snak.change_dir(direction::down);
            break;
        case KEY_LEFT:
            //printw( "Left" ) ;  // key left
            snak.change_dir(direction::left);
            break;
        case KEY_RIGHT:
            //printw( "Right" );  // key right
            snak.change_dir(direction::right);
            break;
        default:
            break;
        }
        
    }
    

int main() {
    gameMap gm;
    snake snak;

    gm.random_apple();

    initscr();
    keypad(stdscr, true);
    noecho();
    nodelay(stdscr, TRUE);
    cbreak();

    while (true) {
        check_key_press(snak);

        gm.update_snake(snak);
        gm.draw();
        refresh();
        cbreak();

        snak.move_snake();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        
    }
    endwin();
}