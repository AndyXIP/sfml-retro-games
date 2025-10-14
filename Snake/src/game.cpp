#include "game.h"
#include <iostream>

Game::Game()
    : window(sf::VideoMode({BOARD_WIDTH * CELL_SIZE, BOARD_HEIGHT * CELL_SIZE}), "Snake"),
      playerSnake(BOARD_WIDTH / 2, BOARD_HEIGHT / 2, CELL_SIZE),
      gameBoard(BOARD_WIDTH, BOARD_HEIGHT, CELL_SIZE),
      gameFood(BOARD_WIDTH, BOARD_HEIGHT, CELL_SIZE),
      score(0),
      gameOver(false)
{
    window.setFramerateLimit(60);
    spawnFood();
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        
        if (!gameOver && gameClock.getElapsedTime().asSeconds() > MOVE_DELAY) {
            update();
            gameClock.restart();
        }
        
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
            else if (!gameOver) {
                switch (keyPressed->scancode) {
                    case sf::Keyboard::Scancode::W:
                    case sf::Keyboard::Scancode::Up:
                        playerSnake.setDirection(Direction::UP);
                        break;
                    case sf::Keyboard::Scancode::S:
                    case sf::Keyboard::Scancode::Down:
                        playerSnake.setDirection(Direction::DOWN);
                        break;
                    case sf::Keyboard::Scancode::A:
                    case sf::Keyboard::Scancode::Left:
                        playerSnake.setDirection(Direction::LEFT);
                        break;
                    case sf::Keyboard::Scancode::D:
                    case sf::Keyboard::Scancode::Right:
                        playerSnake.setDirection(Direction::RIGHT);
                        break;
                    default:
                        break;
                }
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::R) {
                resetGame();
            }
        }
    }
}

void Game::update() {
    playerSnake.move();
    checkCollisions();
}

void Game::render() {
    window.clear(sf::Color::Black);
    
    gameBoard.draw(window);
    playerSnake.draw(window);
    gameFood.draw(window);
    
    window.display();
}

void Game::checkCollisions() {
    sf::Vector2i headPos = playerSnake.getHeadPosition();
    
    // Check wall collision
    if (!gameBoard.isValidPosition(headPos.x, headPos.y)) {
        gameOver = true;
        return;
    }
    
    // Check self collision
    if (playerSnake.checkSelfCollision()) {
        gameOver = true;
        return;
    }
    
    // Check food collision
    if (headPos == gameFood.getPosition()) {
        playerSnake.grow();
        score += 10;
        spawnFood();
    }
}

void Game::spawnFood() {
    gameFood.spawn();
    
    // Make sure food doesn't spawn on snake
    sf::Vector2i headPos = playerSnake.getHeadPosition();
    while (gameFood.getPosition() == headPos) {
        gameFood.spawn();
    }
}

void Game::resetGame() {
    playerSnake.reset(BOARD_WIDTH / 2, BOARD_HEIGHT / 2);
    score = 0;
    gameOver = false;
    spawnFood();
    gameClock.restart();
}