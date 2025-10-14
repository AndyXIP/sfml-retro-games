#include "food.h"
#include <chrono>

Food::Food(int boardWidth, int boardHeight, int size)
    : cellSize(size),
      rng(std::chrono::steady_clock::now().time_since_epoch().count()),
      xDist(0, boardWidth - 1),
      yDist(0, boardHeight - 1)
{
    // Setup visual representation
    shape.setRadius(cellSize / 2.0f - 1);
    shape.setFillColor(sf::Color::Red);
    
    spawn();
}

void Food::spawn() {
    position.x = xDist(rng);
    position.y = yDist(rng);
    
    // Update visual position
    shape.setPosition({
        static_cast<float>(position.x * cellSize + 1),
        static_cast<float>(position.y * cellSize + 1)
    });
}

void Food::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::Vector2i Food::getPosition() const {
    return position;
}

void Food::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
    
    // Update visual position
    shape.setPosition({
        static_cast<float>(position.x * cellSize + 1),
        static_cast<float>(position.y * cellSize + 1)
    });
}