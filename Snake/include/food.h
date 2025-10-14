#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>
#include <random>

/**
 * @class Food
 * @brief Represents a food item in the Snake game.
 *
 * The food spawns at random locations and can be consumed by the snake.
 */
class Food {
    private:
        sf::Vector2i position;
        sf::CircleShape shape;
        int cellSize;
        std::mt19937 rng;
        std::uniform_int_distribution<int> xDist;
        std::uniform_int_distribution<int> yDist;
        
    public:
        /**
         * @brief Constructs a Food object.
         * @param boardWidth Width of the game board in cells.
         * @param boardHeight Height of the game board in cells.
         * @param size Size of each cell in pixels.
         */
        Food(int boardWidth, int boardHeight, int size);
        
        /**
         * @brief Spawns food at a random position.
         */
        void spawn();
        
        /**
         * @brief Draws the food to the window.
         * @param window The SFML render window.
         */
        void draw(sf::RenderWindow& window);
        
        /**
         * @brief Gets the position of the food.
         * @return Vector2i representing food position in grid coordinates.
         */
        sf::Vector2i getPosition() const;
        
        /**
         * @brief Sets the position of the food.
         * @param x X coordinate in grid.
         * @param y Y coordinate in grid.
         */
        void setPosition(int x, int y);
};

#endif