//
// Created by lactosis on 19.7.19.
//

#include <ai/minmax/FullSearchPlayer.h>
#include <ai/minmax/GameState.h>
#include <iostream>


Direction FullSearchPlayer::makeMove(Grid grid) {
    GameState g(grid.getGrid(), grid.getWidth(), grid.getHeight(), 1);

    double bestValue = 0;
    Direction bestDirection = UP;
    bestValue = considerDirection(g, UP, INSIGHT);
    std::cout << "Current grid: "
              << std::endl << grid.toString() << std::endl;
    std::cout << "  UP value: " << bestValue << std::endl;
    double currValue = considerDirection(g, LEFT, INSIGHT);
    std::cout << "  LEFT value: " << currValue << std::endl;
    if (currValue > bestValue) {
        bestValue = currValue;
        bestDirection = LEFT;
    }


    currValue = considerDirection(g, DOWN, INSIGHT);
    std::cout << "  DOWN value: " << currValue << std::endl;
    if (currValue > bestValue) {
        bestValue = currValue;
        bestDirection = DOWN;
    }

    currValue = considerDirection(g, RIGHT, INSIGHT);
    std::cout << "  RIGHT value: " << currValue << std::endl;
    if (currValue > bestValue) {
        bestDirection = RIGHT;
    }

    return bestDirection;
}

double FullSearchPlayer::considerDirection(GameState state, Direction direction, int depthLeft) {
    if (!state.canMakeTurn(direction)) return 0;
    if (depthLeft == 0)
        return state.getProbScore();

    std::vector<GameState> childrenStates = state.getChildrenStates(direction);
    if (childrenStates.empty()) {
        return state.getProbScore();
    }
    double sum = 0;
    for (const GameState &gs : childrenStates) {
        if (depthLeft == 1) {
            sum += gs.getProbScore();
        } else {
            sum += considerDirection(gs, UP, depthLeft - 1);
            sum += considerDirection(gs, LEFT, depthLeft - 1);
            sum += considerDirection(gs, DOWN, depthLeft - 1);
            sum += considerDirection(gs, RIGHT, depthLeft - 1);
        }
    }
    return sum;
}

bool FullSearchPlayer::isInteractive() {
    return false;
}

void FullSearchPlayer::userPromptedTurn(Direction direction) {}
