//
// Created by lactosis on 13.7.19.
//

#include <game/Controller.h>

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
    update();
}

void Controller::rollback() {

}

void Controller::spacePressed() {
    if (game->gameOver()) {
        game->resetGame();
    } else {
        window->showPrompt("Do you really want to restart the game?");
    }
}
