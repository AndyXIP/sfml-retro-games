#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>
#include "snake.h"
#include "food.h"
#include "board.h"

/**
 * @class Game
 * @brief Manages the Snake game loop and state.
 * 
 * Handles input processing, game logic, collision detection, rendering,
 * and game state management.
 */
class Game {
    private:
        sf::RenderWindow window;
        Snake playerSnake;
        Board gameBoard;
        Food gameFood;
        
        int score;
        bool gameOver;
        bool fontLoaded;
        sf::Clock gameClock;
        sf::Font font;
        
        static constexpr int CELL_SIZE = 20;
        static constexpr int BOARD_WIDTH = 30;
        static constexpr int BOARD_HEIGHT = 20;
        static constexpr float MOVE_DELAY = 0.15f; // seconds between moves
        
        /**
         * @brief Processes window and input events.
         */
        void processEvents();
        
        /**
         * @brief Updates game state including snake movement and collision detection.
         */
        void update();
        
        /**
         * @brief Renders all game objects to the window.
         */
        void render();
        
        /**
         * @brief Checks for collisions between snake and food/walls/self.
         */
        void checkCollisions();
        
        /**
         * @brief Spawns new food at random position.
         */
        void spawnFood();
        
        /**
         * @brief Resets game state for new game.
         */
        void resetGame();
        
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