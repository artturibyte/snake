#include "gameMap.hpp"
#include <iostream>
#include <ncurses.h>
#include <chrono>
#include <thread>


int main() {
    sf::RenderWindow game_window{{800, 500}, "game"};
    gameMap gm;
    snake snak;

    gm.random_apple();

    initscr();
    keypad(stdscr, true);
    noecho();
    nodelay(stdscr, TRUE);
    cbreak();

    while (true) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        snak.change_dir(direction::up);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            snak.change_dir(direction::down);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            snak.change_dir(direction::left);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            snak.change_dir(direction::right);
        }
        snak.move_snake();
        gm.update_snake(snak);
        gm.draw();
        refresh();
        cbreak();

        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            break;
    }
    endwin();
}