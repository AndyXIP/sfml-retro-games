#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "board.h"

/**
 * @class Game
 * @brief Manages the Tic Tac Toe game loop and state.
 * 
 * Handles input processing, game logic (win/draw checks), rendering,
 * and player turns.
 */
class Game {
    private:
        sf::RenderWindow window;
        Board board;
        int currentPlayer;       ///< Tracks the current player (1 for X, 2 for O).
        bool gameOver;
        /**
         * @brief Processes window and input events.
         */
        void processEvents();

        /**
         * @brief Renders the game objects on the window.
         */
        void render();
        
        /**
         * @brief Handles mouse click events at the specified window coordinates.
         * 
         * @param x The x-coordinate of the mouse click.
         * @param y The y-coordinate of the mouse click.
         */
        void handleClick(int x, int y);

        /**
         * @brief Checks if the specified player has won the game.
         * 
         * @param player The player number to check (1 or 2).
         * @return True if the player has a winning combination; false otherwise.
         */
        bool checkWin(int player);

        /**
         * @brief Checks if the game is a draw (no empty cells left).
         * 
         * @return True if the game is a draw; false otherwise.
         */
        bool checkDraw();

    public:
        /**
         * @brief Constructs and initializes the game.
         */
        Game();

        /**
         * @brief Runs the main game loop.
         */
        void run();
};

#endif
