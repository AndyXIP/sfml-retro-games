#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

/**
 * @class Board
 * @brief Represents the Tic Tac Toe game board.
 *
 * The Board class handles grid rendering, cell state management, and position tracking.
 */
class Board {
    private:
        int board[3][3]; ///< 3x3 array representing the game board (0 = empty, 1 = X, 2 = O).
        float cellSize; ///< Size of each cell in pixels.
        sf::Vector2f position; ///< Top-left position of the board on the screen.
        sf::RectangleShape gridLines[4]; ///< Array of grid lines used to draw the board.

    public:
        /**
         * @brief Constructs a game board.
         * 
         * @param size The size of each cell in the board.
         * @param pos The position to place the board on the screen.
         */
        Board(float size, sf::Vector2f pos);

        /**
         * @brief Draws the game board grid on the given window.
         * 
         * @param window The SFML window to draw on.
         */
        void draw(sf::RenderWindow& window);

        /**
         * @brief Sets the cell value at the specified row and column.
         * 
         * @param row The row index (0–2).
         * @param col The column index (0–2).
         * @param player The player number (1 = X, 2 = O).
         */
        void setCell(int row, int col, int player);

        /**
         * @brief Gets the player value at a given board coordinate.
         * 
         * @param x The x-coordinate (column index).
         * @param y The y-coordinate (row index).
         * @return The value in the cell: 0 (empty), 1 (X), or 2 (O).
         */
        int getCell(int x, int y);

        /**
         * @brief Gets the position of the top-left corner of the board.
         * 
         * @return The position as a 2D vector.
         */
        sf::Vector2f getPosition();

        /**
         * @brief Gets the size of a single cell in pixels.
         * 
         * @return The cell size.
         */
        int getCellSize();
};

#endif
