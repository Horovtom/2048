//
// Created by lactosis on 12.7.19.
//

#include <iostream>
#include "game/logic/Game.h"
#include "game/logic/Direction.h"

Game::Game(int width, int height) : w(width), h(height), grid(width, height) {
    std::cout << "I am in the constructor of Game with w: " << w << ", h: " << h << std::endl;
}

std::vector<std::vector<int>> Game::getState() {
    return grid.getGrid2D();
}

int Game::getWidth() {
    return w;
}

int Game::getHeight() {
    return h;
}

int Game::getScore() {
    return grid.getScore();
}

void Game::makeTurn(Direction direction) {
    grid.makeTurn(direction);
}

void Game::resetGame() {
    // TODO: IMPLEMENT
}

bool Game::gameOver() {
    return !grid.canMakeTurn();
}
