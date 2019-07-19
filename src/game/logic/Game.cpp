//
// Created by lactosis on 12.7.19.
//

#include <iostream>
#include "game/logic/Game.h"
#include "game/logic/Direction.h"

Game::Game(int width, int height, Player *player) : w(width), h(height), grid(width, height), player(player) {

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
    grid.resetGrid();
}

bool Game::gameOver() {
    return !grid.canMakeTurn();
}

Player *Game::getPlayer() {
    return player;
}

void Game::nextTurn() {
    makeTurn(player->makeMove(grid));
}
