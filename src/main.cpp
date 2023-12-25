#include "gameMap.hpp"
#include <iostream>
#include <ncurses.h>
#include <chrono>
#include <thread>

void check_key_press(snake &snak) {
    int ch;
    if ((ch = getch()) != ERR) {
            switch((ch=getch())) {
        case KEY_UP:
            //printw("Up") ; //key up
            snak.move_up();
            break;
        case KEY_DOWN:
            //printw("Down")  ;   // key down
            snak.move_down();
            break;
        case KEY_LEFT:
            //printw( "Left" ) ;  // key left
            snak.move_left();
            break;
        case KEY_RIGHT:
            //printw( "Right" );  // key right
            snak.move_right();
            break;
        default:
            break;
        }
        }
    }
    

int main() {
    gameMap gm;
    snake snak;


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
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    	
    }
    endwin();
}