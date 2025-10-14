#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>

/**
 * @class Board
 * @brief Represents the Snake game board.
 *
 * The Board class handles grid rendering and boundary management.
 */
class Board {
    private:
        int width;
        int height;
        int cellSize;
        sf::RectangleShape border;
        
    public:
        /**
         * @brief Constructs a Board object.
         * @param boardWidth Width of the board in cells.
         * @param boardHeight Height of the board in cells.
         * @param size Size of each cell in pixels.
         */
        Board(int boardWidth, int boardHeight, int size);
        
        /**
         * @brief Draws the game board to the window.
         * @param window The SFML render window.
         */
        void draw(sf::RenderWindow& window);
        
        /**
         * @brief Checks if a position is within board boundaries.
         * @param x X coordinate in grid.
         * @param y Y coordinate in grid.
         * @return True if position is valid.
         */
        bool isValidPosition(int x, int y) const;
        
        /**
         * @brief Gets the board width.
         * @return Width in cells.
         */
        int getWidth() const;
        
        /**
         * @brief Gets the board height.
         * @return Height in cells.
         */
        int getHeight() const;
};

#endif