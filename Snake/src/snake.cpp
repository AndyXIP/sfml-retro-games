#include "snake.h"

Snake::Snake(int startX, int startY, int size)
    : currentDirection(Direction::RIGHT),
      nextDirection(Direction::RIGHT),
      cellSize(size)
{
    // Initialize snake with 3 segments
    body.push_back({startX, startY});
    body.push_back({startX - 1, startY});
    body.push_back({startX - 2, startY});
    
    // Setup visual representation
    bodySegment.setSize(sf::Vector2f(cellSize - 1, cellSize - 1));
    bodySegment.setFillColor(sf::Color::Green);
}

void Snake::move() {
    // Update direction (prevents instant direction reversal)
    currentDirection = nextDirection;
    
    // Calculate new head position
    sf::Vector2i newHead = body.front();
    
    switch (currentDirection) {
        case Direction::UP:
            newHead.y--;
            break;
        case Direction::DOWN:
            newHead.y++;
            break;
        case Direction::LEFT:
            newHead.x--;
            break;
        case Direction::RIGHT:
            newHead.x++;
            break;
        default:
            break;
    }
    
    // Add new head
    body.push_front(newHead);
    
    // Remove tail (will be restored if growing)
    body.pop_back();
}

void Snake::setDirection(Direction newDirection) {
    // Prevent reversing into self
    if ((currentDirection == Direction::UP && newDirection == Direction::DOWN) ||
        (currentDirection == Direction::DOWN && newDirection == Direction::UP) ||
        (currentDirection == Direction::LEFT && newDirection == Direction::RIGHT) ||
        (currentDirection == Direction::RIGHT && newDirection == Direction::LEFT)) {
        return;
    }
    
    nextDirection = newDirection;
}

void Snake::grow() {
    sf::Vector2i tail = body.back();
    body.push_back(tail);
}

void Snake::draw(sf::RenderWindow& window) {
    for (size_t i = 0; i < body.size(); ++i) {
        bodySegment.setPosition({static_cast<float>(body[i].x * cellSize), static_cast<float>(body[i].y * cellSize)});
        
        // Make head slightly different color
        if (i == 0) {
            bodySegment.setFillColor(sf::Color(0, 200, 0)); // Brighter green for head
        } else {
            bodySegment.setFillColor(sf::Color(0, 150, 0)); // Darker green for body
        }
        
        window.draw(bodySegment);
    }
}

sf::Vector2i Snake::getHeadPosition() const {
    return body.front();
}

bool Snake::checkSelfCollision() const {
    const sf::Vector2i& head = body.front();
    
    for (size_t i = 1; i < body.size(); ++i) {
        if (head == body[i]) {
            return true;
        }
    }
    
    return false;
}

void Snake::reset(int startX, int startY) {
    body.clear();
    
    body.push_back({startX, startY});
    body.push_back({startX - 1, startY});
    body.push_back({startX - 2, startY});
    
    currentDirection = Direction::RIGHT;
    nextDirection = Direction::RIGHT;
}

size_t Snake::getSize() const {
    return body.size();
}