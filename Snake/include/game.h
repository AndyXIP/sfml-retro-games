#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "snake.h"

class Game {
    private:
        Board board;
        Snake snake;
    public:
        Game();
        void run();
};

#endif