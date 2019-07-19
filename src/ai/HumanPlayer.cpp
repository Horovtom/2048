//
// Created by lactosis on 19.7.19.
//

#include <ai/HumanPlayer.h>

Direction HumanPlayer::makeMove(Grid grid) {
    return turnPrompted;
}

bool HumanPlayer::isInteractive() {
    return true;
}

void HumanPlayer::userPromptedTurn(Direction direction) {
    turnPrompted = direction;
}
