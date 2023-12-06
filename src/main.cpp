#include "gameMap.h"
#include <iostream>
#include <ncurses.h>
#include <chrono>
#include <thread>



int main() {
    gameMap gm;
    snake snak;

    int ch;

    initscr();
    keypad(stdscr, true);
    noecho();
        
    while (true) {
        //ch=getch();
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
        
        refresh();
      
        gm.update_snake(snak);
        gm.draw();
        snak.move_snake();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    	
    }
    endwin();
}