#include "game.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Rect.hpp>

Game::Game()
    : window(sf::VideoMode(sf::Vector2u(800, 600)), "Pong"),
      player1(50.f, 250.f),
      player2(740.f, 250.f),
      ball(400.f, 300.f)
    {
        window.setFramerateLimit(60);
    }

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    while (const std::optional<sf::Event> eventOpt = window.pollEvent()) {
        const sf::Event& event = *eventOpt;

        if (event.is<sf::Event::Closed>()) {
            window.close();
        }
        else if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                window.close();
            }
        }
    }

    // Player 1 controls (W/S)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        player1.move(-5.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        player1.move(5.f);
    }

    // Player 2 controls (Up/Down)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        player2.move(-5.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        player2.move(5.f);
    }
}

void Game::update() {
    ball.update();

    // Ball collision with top/bottom
    if (ball.getPosition().y <= 0 || ball.getPosition().y + 10.f * 2 >= 600) {
        ball.bounceY();
    }

    // Ball collision with paddles
    if (ball.getBounds().findIntersection(player1.getBounds()) || 
        ball.getBounds().findIntersection(player2.getBounds())) {
        ball.bounceX();
    }

    // Ball out of bounds (reset)
    if (ball.getPosition().x < 0 || ball.getPosition().x > 800) {
        ball.reset();
    }
}

void Game::render() {
    window.clear(sf::Color::Black);
    player1.draw(window);
    player2.draw(window);
    ball.draw(window);
    window.display();
}
