#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

/**
 * @class Paddle
 * @brief Represents a paddle in the Pong game.
 * 
 * The Paddle class handles rendering, movement, and position control
 * for one of the player paddles.
 */
class Paddle {
    private:
        sf::RectangleShape shape; ///< Graphical representation of the paddle.

    public:
        /**
         * @brief Constructs a Paddle object at the specified position.
         * 
         * @param x The initial X-coordinate of the paddle.
         * @param y The initial Y-coordinate of the paddle.
         */
        Paddle(float x, float y);

        /**
         * @brief Moves the paddle vertically.
         * 
         * @param dy The amount to move along the Y-axis.
         */
        void move(double dy);

        /**
         * @brief Draws the paddle onto the given render target.
         * 
         * @param target The SFML render target (e.g., window) to draw the paddle on.
         */
        void draw(sf::RenderTarget& target) const;

        /**
         * @brief Gets the bounding rectangle of the paddle.
         * 
         * @return A FloatRect representing the paddle's bounds (used for collision detection).
         */
        sf::FloatRect getBounds() const;

        /**
         * @brief Sets the position of the paddle.
         * 
         * @param x The new X-coordinate.
         * @param y The new Y-coordinate.
         */
        void setPosition(float x, float y);

        /**
         * @brief Gets the current position of the paddle.
         * 
         * @return The paddle's current position as a 2D vector.
         */
        sf::Vector2f getPosition() const;
};

#endif
