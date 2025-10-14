#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <deque>

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

/**
 * @class Snake
 * @brief Represents the snake entity in the game.
 * 
 * Manages snake movement, growth, rendering, and collision detection.
 */
class Snake {
    private:
        std::deque<sf::Vector2i> body;
        Direction currentDirection;
        Direction nextDirection;
        int cellSize;
        sf::RectangleShape bodySegment;
        
    public:
        /**
         * @brief Constructs a Snake object.
         * @param startX Starting X position in grid coordinates.
         * @param startY Starting Y position in grid coordinates.
         * @param size Size of each cell in pixels.
         */
        Snake(int startX, int startY, int size);
        
        /**
         * @brief Moves the snake in the current direction.
         */
        void move();
        
        /**
         * @brief Changes the snake's direction.
         * @param newDirection The new direction to move.
         */
        void setDirection(Direction newDirection);
        
        /**
         * @brief Grows the snake by one segment.
         */
        void grow();
        
        /**
         * @brief Draws the snake to the window.
         * @param window The SFML render window.
         */
        void draw(sf::RenderWindow& window);
        
        /**
         * @brief Gets the position of the snake's head.
         * @return Vector2i representing head position in grid coordinates.
         */
        sf::Vector2i getHeadPosition() const;
        
        /**
         * @brief Checks if the snake has collided with itself.
         * @return True if self-collision occurred.
         */
        bool checkSelfCollision() const;
        
        /**
         * @brief Resets snake to initial state.
         * @param startX Starting X position.
         * @param startY Starting Y position.
         */
        void reset(int startX, int startY);
        
        /**
         * @brief Gets the current size of the snake.
         * @return Number of body segments.
         */
        size_t getSize() const;
};

#endif