//
// Created by lactosis on 19.7.19.
//

#ifndef INC_2048_GAMESTATE_H
#define INC_2048_GAMESTATE_H


#include <game/logic/Grid.h>

class GameState : public Grid {

public:
    GameState(std::vector<int> grid, int width, int height, double probability);

    /**
     * Calculates all possible outcomes of a turn.
     * @return A vector with all possible GameStates that you can reach from this GameState using the specified Direction.
     * If the returned vector is empty, this has to be losing state
     */
    std::vector<GameState> getChildrenStates(Direction direction);

    /**
     * Probability of reaching this GameState from the previous GameState
     */
    double probability;

    double getProbScore() const;
};


#endif //INC_2048_GAMESTATE_H
