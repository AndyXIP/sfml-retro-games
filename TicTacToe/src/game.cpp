#include "game.h"

Game::Game()
    : window(sf::VideoMode({600, 600}), "TicTacToe"),
      board(180.f, {60.f, 60.f}),
      currentPlayer(1), gameOver(false)
{}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        render();
    }
}

void Game::processEvents() {
    while (auto eventOpt = window.pollEvent()) {
        const sf::Event& event = *eventOpt;

        if (event.is<sf::Event::Closed>()) {
            window.close();
        }
        else if (auto keyPressed = event.getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                window.close();
            }
        }
        else if (auto mousePressed = event.getIf<sf::Event::MouseButtonPressed>()) {
            if (!gameOver && mousePressed->button == sf::Mouse::Button::Left) {
                int x = mousePressed->position.x;
                int y = mousePressed->position.y;
                handleClick(x, y);
            }
        }
    }
}

void Game::handleClick(int x, int y) {
    // Convert mouse coords to board cell
    int col = (x - static_cast<int>(board.getPosition().x)) / static_cast<int>(board.getCellSize());
    int row = (y - static_cast<int>(board.getPosition().y)) / static_cast<int>(board.getCellSize());

    // Check valid cell and empty
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board.getCell(row, col) == 0) {
        board.setCell(row, col, currentPlayer);

        if (checkWin(currentPlayer)) {
            gameOver = true;
            // TODO: add win message or logic
        } else if (checkDraw()) {
            gameOver = true;
            // TODO: add draw message or logic
        } else {
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
    }
}

bool Game::checkWin(int player) {
    for (int i = 0; i < 3; ++i) {
        if (board.getCell(i, 0) == player && board.getCell(i, 1) == player && board.getCell(i, 2) == player)
            return true;
        if (board.getCell(0, i) == player && board.getCell(1, i) == player && board.getCell(2, i) == player)
            return true;
    }
    if (board.getCell(0, 0) == player && board.getCell(1, 1) == player && board.getCell(2, 2) == player)
        return true;
    if (board.getCell(0, 2) == player && board.getCell(1, 1) == player && board.getCell(2, 0) == player)
        return true;
    return false;
}

bool Game::checkDraw() {
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            if (board.getCell(r, c) == 0)
                return false;
    return true;
}

void Game::render() {
    window.clear(sf::Color::White);
    board.draw(window);
    window.display();
}