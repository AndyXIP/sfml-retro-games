#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Paddle {
    private:
        sf::RectangleShape shape;
        
    public:
        Paddle(float x, float y);
        void move(double dy);
        void draw(sf::RenderTarget& target) const;
        sf::FloatRect getBounds() const;
        void setPosition(float x, float y);
        sf::Vector2f getPosition() const;
};

#endif