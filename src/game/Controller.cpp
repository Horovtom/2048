//
// Created by lactosis on 13.7.19.
//

#include <game/Controller.h>
#include <iostream>

Controller::Controller(Game *g, GameWindow *w) {
    window = w;
    game = g;
    w->registerController(this);
}

void Controller::update() {
    std::vector<std::vector<int>> gameState = game->getState();
    int width = game->getWidth();
    int height = game->getHeight();
    int score = game->getScore();
    window->setData(gameState, width, height, score);
}

void Controller::onUserAction(Direction direction) {
    game->makeTurn(direction);
    restartPrompt = false;
    update();
    if (game->gameOver()) window->showPrompt("Game OVER! Press space for restart");
}

void Controller::rollback() {
    //TODO: IMPLEMENT
}

void Controller::spacePressed() {
    if (game->gameOver() || restartPrompt) {
        std::cout << "Resetting the game " << std::endl;
        game->resetGame();
        restartPrompt = false;
        update();
    } else {
        window->showPrompt("Do you really want to restart the game?");
        restartPrompt = true;
    }
}
