#include "mark.h"

XMark::XMark(float cellSize) {
    float thickness = 5.f;
    float length = cellSize * 0.8f;
    
    line1.setSize({length, thickness});
    line1.setOrigin(sf::Vector2f(length / 2, thickness / 2));
    line1.setFillColor(sf::Color::Red);

    line2.setSize({length, thickness});
    line2.setOrigin(sf::Vector2f(length / 2, thickness / 2));
    line2.setFillColor(sf::Color::Red);

    line1.setRotation(sf::degrees(45.f));
    line2.setRotation(sf::degrees(-45.f));
}

void XMark::setPosition(sf::Vector2f pos) {
    line1.setPosition(pos);
    line2.setPosition(pos);
}

void XMark::draw(sf::RenderWindow& window) {
    window.draw(line1);
    window.draw(line2);
}

OMark::OMark(float cellSize) : circle(cellSize * 0.35f) {
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineColor(sf::Color::Blue);
    circle.setOutlineThickness(5.f);
    circle.setOrigin(sf::Vector2f(circle.getRadius(), circle.getRadius()));
}

void OMark::setPosition(sf::Vector2f pos) {
    circle.setPosition(pos);
}

void OMark::draw(sf::RenderWindow& window) {
    window.draw(circle);
}
