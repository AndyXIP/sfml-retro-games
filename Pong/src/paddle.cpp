#include "paddle.h"
#include <SFML/Graphics/Color.hpp>

Paddle::Paddle(float x, float y) {
    shape.setSize({10.f, 100.f});
    shape.setFillColor(sf::Color::White);
    shape.setPosition(sf::Vector2f(x, y));
}

void Paddle::move(double dy) {
    shape.move(sf::Vector2f(0, dy));
    
    sf::Vector2f pos = shape.getPosition();

    // Clamp the Y position between 0 and (windowHeight - paddleHeight)
    if (pos.y < 0.f) {
        pos.y = 0.f;
    } else if (pos.y + shape.getSize().y > 600.f) {  // Assuming 600 is window height
        pos.y = 600.f - shape.getSize().y;
    }

    // Set the corrected position
    shape.setPosition(pos);
}

void Paddle::draw(sf::RenderTarget& target) const {
    target.draw(shape);
}

sf::FloatRect Paddle::getBounds() const {
    return shape.getGlobalBounds();
}

void Paddle::setPosition(float x, float y) {
    shape.setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Paddle::getPosition() const {
    return shape.getPosition();
}
