#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "paddle.h"
#include "ball.h"

/**
 * @class Game
 * @brief Manages the main game loop and game state for Pong.
 * 
 * The Game class encapsulates the core game logic, including input handling,
 * updating game objects, and rendering them to the screen.
 */
class Game {
    private:
        sf::RenderWindow window;
        Paddle player1;
        Paddle player2;
        Ball ball;

        /**
         * @brief Handles player input and system events.
         */
        void processEvents();

        /**
         * @brief Updates the game state, including paddle and ball movement.
         */
        void update();

        /**
         * @brief Renders all game objects to the window.
         */
        void render();
        
    public:
        /**
         * @brief Constructs a Game object and initializes game state.
         */
        Game();

        /**
         * @brief Runs the main game loop.
         */
        void run();
};

#endif
