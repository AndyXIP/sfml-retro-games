#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Ball {
    private:
        sf::CircleShape shape;
        sf::Vector2f velocity;
        float speed = 4.0f;
        
    public:
        Ball(float x, float y);
        void update();
        void draw(sf::RenderTarget& target) const;
        void reset();
        void bounceX();
        void bounceY();
        sf::FloatRect getBounds() const;
        sf::Vector2f getPosition() const;
        void setPosition(float x, float y);
        sf::Vector2f getVelocity() const;
};

#endif