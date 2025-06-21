#ifndef MARK_H
#define MARK_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class Mark {
    public:
        virtual void setPosition(sf::Vector2f pos) = 0;
        virtual void draw(sf::RenderWindow& window) = 0;
        virtual ~Mark() = default;
};

class XMark : public Mark {
    private:
        sf::RectangleShape line1, line2;
    public:
        XMark(float cellSize);
        void setPosition(sf::Vector2f pos) override;
        void draw(sf::RenderWindow& window) override;
};

class OMark : public Mark {
    private:
        sf::CircleShape circle;
    public:
        OMark(float cellSize);
        void setPosition(sf::Vector2f pos) override;
        void draw(sf::RenderWindow& window) override;
};

#endif