#include "ball.h"
#include <SFML/Graphics/Color.hpp>

Ball::Ball(float x, float y) {
    shape.setRadius(10.f);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(sf::Vector2f(10, 10));
    shape.setPosition(sf::Vector2f(x, y));
    velocity = {speed, speed};
}

void Ball::update() {
    shape.move(velocity);
}

void Ball::draw(sf::RenderTarget& target) const {
    target.draw(shape);
}

void Ball::reset() {
    shape.setPosition(sf::Vector2f(400, 300));
    velocity = {speed, speed};
}

void Ball::bounceX() {
    velocity.x = -velocity.x;
}

void Ball::bounceY() {
    velocity.y = -velocity.y;
}

sf::FloatRect Ball::getBounds() const {
    return shape.getGlobalBounds();
}

sf::Vector2f Ball::getPosition() const {
    return shape.getPosition();
}

void Ball::setPosition(float x, float y) {
    shape.setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Ball::getVelocity() const {
    return velocity;
}
