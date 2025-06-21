#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "board.h"

class Game {
    private:
        sf::RenderWindow window;
        Board board;
        int currentPlayer;
        bool gameOver;

        void processEvents();
        void update();
        void render();
        
        void handleClick(int x, int y);
        bool checkWin(int player);
        bool checkDraw();

    public:
        Game();
        void run();
};

#endif