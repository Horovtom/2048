//
// Created by lactosis on 11.8.19.
//

#include "ai/minmax/MinMaxPlayer.h"
#include <ai/minmax/GameState.h>
#include <iostream>


Direction MinMaxPlayer::makeMove(Grid grid) {
    GameState g(grid.getGrid(), grid.getWidth(), grid.getHeight(), 1);

    // Find maximum of each direction:
    double maximum;
    Direction optimalDirection;
    maximum = considerDirection(g, UP, INSIGHT, 0);
    optimalDirection = UP;
    double curVal = considerDirection(g, DOWN, INSIGHT, maximum);
    if (curVal > maximum) {
        maximum = curVal;
        optimalDirection = DOWN;
    }

    curVal = considerDirection(g, RIGHT, INSIGHT, maximum);
    if (curVal > maximum) {
        maximum = curVal;
        optimalDirection = RIGHT;
    }

    curVal = considerDirection(g, LEFT, INSIGHT, maximum);
    if (curVal > maximum) {
        optimalDirection = LEFT;
    }

    return optimalDirection;
}


double MinMaxPlayer::considerDirection(GameState state, Direction direction, int depthLeft, double maxFound) {
    if (!state.canMakeTurn(direction)) return 0;
    if (depthLeft == 0)
        return state.getProbScore();

    std::vector<GameState> childrenStates = state.getChildrenStates(direction);
    if (childrenStates.empty()) {
        return state.getProbScore();
    }
    double bestSum = 0;
    // Choose the worst of those:

    for (const GameState &gs : childrenStates) {
        if (depthLeft == 1) {
            bestSum += gs.getProbScore();
        } else {
            double best = 0;
            // And the best of these.
            best = considerDirection(gs, UP, depthLeft - 1, maxFound);
            double curr = considerDirection(gs, LEFT, depthLeft - 1, maxFound);
            if (curr > best) best = curr;
            curr = considerDirection(gs, DOWN, depthLeft - 1, maxFound);
            if (curr > best) best = curr;
            curr = considerDirection(gs, RIGHT, depthLeft - 1, maxFound);
            if (curr > best) best = curr;
            // We found something considerably worse
            if (best < maxFound) return 0;
            if (bestSum < best) bestSum = best;
        }
    }
    return bestSum;
}

bool MinMaxPlayer::isInteractive() {
    return false;
}

void MinMaxPlayer::userPromptedTurn(Direction direction) {}
