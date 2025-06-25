#ifndef MARK_H
#define MARK_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

/**
 * @class Mark
 * @brief Abstract base class representing a mark (X or O) in Tic Tac Toe.
 *
 * Defines the common interface for placing and rendering a mark on the game board.
 */
class Mark {
    public:
        /**
         * @brief Sets the position of the mark on the board.
         * 
         * @param pos The position as an SFML 2D vector.
         */
        virtual void setPosition(sf::Vector2f pos) = 0;

        /**
         * @brief Draws the mark onto the given render window.
         * 
         * @param window The SFML render window to draw the mark on.
         */
        virtual void draw(sf::RenderWindow& window) = 0;

        /**
         * @brief Virtual destructor for proper cleanup of derived classes.
         */
        virtual ~Mark() = default;
};

/**
 * @class XMark
 * @brief Represents an "X" mark in Tic Tac Toe.
 *
 * Composed of two diagonal lines forming an X.
 */
class XMark : public Mark {
    private:
        sf::RectangleShape line1; ///< First diagonal line of the X.
        sf::RectangleShape line2; ///< Second diagonal line of the X.

    public:
        /**
         * @brief Constructs an XMark with a given cell size.
         * 
         * @param cellSize The size of a cell on the board, used to scale the X.
         */
        XMark(float cellSize);

        /**
         * @brief Sets the position of the X on the board.
         * 
         * @param pos The position as an SFML 2D vector.
         */
        void setPosition(sf::Vector2f pos) override;

        /**
         * @brief Draws the X onto the given render window.
         * 
         * @param window The SFML render window to draw the X on.
         */
        void draw(sf::RenderWindow& window) override;
};

/**
 * @class OMark
 * @brief Represents an "O" mark in Tic Tac Toe.
 *
 * Composed of a hollow circle.
 */
class OMark : public Mark {
    private:
        sf::CircleShape circle; ///< Circular shape representing the O.

    public:
        /**
         * @brief Constructs an OMark with a given cell size.
         * 
         * @param cellSize The size of a cell on the board, used to scale the O.
         */
        OMark(float cellSize);

        /**
         * @brief Sets the position of the O on the board.
         * 
         * @param pos The position as an SFML 2D vector.
         */
        void setPosition(sf::Vector2f pos) override;

        /**
         * @brief Draws the O onto the given render window.
         * 
         * @param window The SFML render window to draw the O on.
         */
        void draw(sf::RenderWindow& window) override;
};

#endif
