#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

/**
 * @class Ball
 * @brief Represents the ball in a Pong game.
 *
 * The Ball class handles the graphical representation, movement,
 * collision response, and state resetting of the ball during gameplay.
 */
class Ball {
    private:
        sf::CircleShape shape;
        sf::Vector2f velocity;
        float speed = 4.0f;

    public:
        /**
         * @brief Constructs a Ball object at the specified position.
         * 
         * @param x The initial X-coordinate.
         * @param y The initial Y-coordinate.
         */
        Ball(float x, float y);

        /**
         * @brief Updates the ball's position based on its current velocity.
         */
        void update();

        /**
         * @brief Draws the ball onto the given render target.
         * 
         * @param target The SFML render target (e.g., window) to draw the ball on.
         */
        void draw(sf::RenderTarget& target) const;

        /**
         * @brief Resets the ball to its initial position and velocity.
         */
        void reset();

        /**
         * @brief Reverses the horizontal component of the ball's velocity.
         */
        void bounceX();

        /**
         * @brief Reverses the vertical component of the ball's velocity.
         */
        void bounceY();

        /**
         * @brief Gets the bounding rectangle of the ball.
         * 
         * @return A FloatRect representing the bounds (useful for collision detection).
         */
        sf::FloatRect getBounds() const;

        /**
         * @brief Gets the current position of the ball.
         * 
         * @return The ball's current position as a 2D vector.
         */
        sf::Vector2f getPosition() const;

        /**
         * @brief Sets the position of the ball.
         * 
         * @param x New X-coordinate.
         * @param y New Y-coordinate.
         */
        void setPosition(float x, float y);

        /**
         * @brief Gets the current velocity of the ball.
         * 
         * @return The ball's velocity as a 2D vector.
         */
        sf::Vector2f getVelocity() const;
};

#endif
