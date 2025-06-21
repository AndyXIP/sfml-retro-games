#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "paddle.h"
#include "ball.h"

class Game {
private:
    sf::RenderWindow window;
    Paddle player1;
    Paddle player2;
    Ball ball;

    void processEvents();
    void update();
    void render();
    
public:
    Game();
    void run();
};

#endif
