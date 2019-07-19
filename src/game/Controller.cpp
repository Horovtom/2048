//
// Created by lactosis on 13.7.19.
//

#include <game/Controller.h>
#include <iostream>

Controller::Controller(Game *g, GameWindow *w) {
    window = w;
    game = g;
    player = g->getPlayer();
    restartPrompt = false;
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
    restartPrompt = false;

    if (!player->isInteractive()) {
        std::cout << "Player is not interactive, throwing the userAction event away" << std::endl;
        return;
    }

    player->userPromptedTurn(direction);
    game->nextTurn();
    update();
    if (game->gameOver()) window->showPrompt("Game OVER! Press R for restart");
}

void Controller::restartPressed() {
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

void Controller::spacePressed() {
    restartPrompt = false;
    if (player->isInteractive()) {
        std::cout << "Player is interactive, throwing the nextTurn event away" << std::endl;
        return;
    }
    game->nextTurn();
    update();
}
