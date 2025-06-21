#include "board.h"

#include <SFML/Graphics/CircleShape.hpp>

Board::Board(float size, sf::Vector2f pos) : cellSize(size), position(pos) {
    // Initialize board to empty
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = 0;

    // Setup grid lines shapes
    for (int i = 0; i < 2; ++i) {
        gridLines[i].setSize({2.f, 3 * cellSize}); // vertical lines
        gridLines[i].setPosition(sf::Vector2f(position.x + (i+1) * cellSize, position.y));
        gridLines[i].setFillColor(sf::Color::Black);

        gridLines[i+2].setSize({3 * cellSize, 2.f}); // horizontal lines
        gridLines[i+2].setPosition(sf::Vector2f(position.x, position.y + (i+1) * cellSize));
        gridLines[i+2].setFillColor(sf::Color::Black);
    }
}

void Board::draw(sf::RenderWindow& window) {
    // Draw grid lines
    for (auto& line : gridLines)
        window.draw(line);

    // Draw X/O for each cell
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            float x = position.x + col * cellSize;
            float y = position.y + row * cellSize;

            if (board[row][col] == 1) {
                // Draw X (two crossing lines)
                sf::RectangleShape line1(sf::Vector2f(cellSize * 0.8f, 5.f));
                line1.setPosition(sf::Vector2f(x + cellSize * 0.1f, y + cellSize * 0.1f));
                line1.setRotation(sf::degrees(45.f));
                line1.setFillColor(sf::Color::Red);

                sf::RectangleShape line2(sf::Vector2f(cellSize * 0.8f, 5.f));
                line2.setPosition(sf::Vector2f(x + cellSize * 0.1f, y + cellSize * 0.9f));
                line2.setRotation(sf::degrees(-45.f));
                line2.setFillColor(sf::Color::Red);

                window.draw(line1);
                window.draw(line2);
            } 
            else if (board[row][col] == 2) {
                // Draw O (circle)
                sf::CircleShape circle(cellSize * 0.35f);
                circle.setPosition(sf::Vector2f(x + cellSize * 0.15f, y + cellSize * 0.15f));
                circle.setFillColor(sf::Color::Transparent);
                circle.setOutlineColor(sf::Color::Blue);
                circle.setOutlineThickness(5.f);

                window.draw(circle);
            }
            // else do nothing for empty cell (0)
        }
    }
}

void Board::setCell(int row, int col, int player) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3)
        board[row][col] = player;
}

int Board::getCell(int x, int y) {
    return board[x][y];
}

sf::Vector2f Board::getPosition() {
    return position;
}

int Board::getCellSize() {
    return cellSize;
}