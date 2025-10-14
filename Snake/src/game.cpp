#include "game.h"
#include <iostream>

Game::Game()
    : window(sf::VideoMode({BOARD_WIDTH * CELL_SIZE, BOARD_HEIGHT * CELL_SIZE + 50}), "Snake"),
      playerSnake(BOARD_WIDTH / 2, BOARD_HEIGHT / 2, CELL_SIZE),
      gameBoard(BOARD_WIDTH, BOARD_HEIGHT, CELL_SIZE),
      gameFood(BOARD_WIDTH, BOARD_HEIGHT, CELL_SIZE),
      score(0),
      gameOver(false),
      fontLoaded(false)
{
    window.setFramerateLimit(60);
    
    // Try to load font (optional - game will work without it)
    if (font.openFromFile("/System/Library/Fonts/Arial.ttf")) {
        fontLoaded = true;
    } else {
        std::cout << "Warning: Could not load font. Score will not be displayed." << std::endl;
    }
    
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
    
    // Draw score
    if (fontLoaded) {
        sf::Text scoreText(font, "Score: " + std::to_string(score), 24);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition({10, BOARD_HEIGHT * CELL_SIZE + 10});
        window.draw(scoreText);
    }
    
    // Draw game over message
    if (gameOver && fontLoaded) {
        sf::Text gameOverText(font, "Game Over! Press R to restart", 36);
        gameOverText.setFillColor(sf::Color::Red);
        gameOverText.setPosition({50, BOARD_HEIGHT * CELL_SIZE / 2});
        window.draw(gameOverText);
    }
    
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