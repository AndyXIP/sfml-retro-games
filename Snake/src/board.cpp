#include "board.h"

Board::Board(int boardWidth, int boardHeight, int size)
    : width(boardWidth),
      height(boardHeight),
      cellSize(size)
{
    // Setup border
    border.setSize(sf::Vector2f(static_cast<float>(width * cellSize), static_cast<float>(height * cellSize)));
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineColor(sf::Color::White);
    border.setOutlineThickness(2);
    border.setPosition({0, 0});
}

void Board::draw(sf::RenderWindow& window) {
    window.draw(border);
    
    // Draw grid lines (optional - makes the grid visible)
    sf::RectangleShape gridLine;
    gridLine.setFillColor(sf::Color(50, 50, 50)); // Dark gray
    
    // Vertical lines
    gridLine.setSize(sf::Vector2f(1, static_cast<float>(height * cellSize)));
    for (int x = 1; x < width; ++x) {
        gridLine.setPosition({static_cast<float>(x * cellSize), 0});
        window.draw(gridLine);
    }
    
    // Horizontal lines
    gridLine.setSize(sf::Vector2f(static_cast<float>(width * cellSize), 1));
    for (int y = 1; y < height; ++y) {
        gridLine.setPosition({0, static_cast<float>(y * cellSize)});
        window.draw(gridLine);
    }
}

bool Board::isValidPosition(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

int Board::getWidth() const {
    return width;
}

int Board::getHeight() const {
    return height;
}