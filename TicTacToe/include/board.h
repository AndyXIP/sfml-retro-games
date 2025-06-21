#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Board {
    private:
        int board[3][3];
        float cellSize;
        sf::Vector2f position;
        sf::RectangleShape gridLines[4];

    public:
        Board(float size, sf::Vector2f pos);
        void draw(sf::RenderWindow& window);
        void setCell(int row, int col, int player);
        int getCell(int x, int y);
        sf::Vector2f getPosition();
        int getCellSize();
};

#endif
