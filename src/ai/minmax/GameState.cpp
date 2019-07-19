#include <utility>

//
// Created by lactosis on 19.7.19.
//

#include <ai/minmax/GameState.h>

std::vector<GameState> GameState::getChildrenStates(Direction direction) {
    std::vector<GameState> result;

    std::vector<int> originalGrid = getGrid();

    if (!canMakeTurn())
        return result;

    shift(direction);
    std::vector<int> shiftedGrid = getGrid();
    std::vector<int> freePlaces = getFreePlaces();

    double probOfPlace = probability / freePlaces.size();

    for (int place : freePlaces) {
        // Number 2:
        setGrid(shiftedGrid);
        setAt(place, 2);
        GameState g2(getGrid(), w, h, probOfPlace * (1.0 - PROB_4));
        result.emplace_back(g2);

        // Number 4:
        setGrid(shiftedGrid);
        setAt(place, 4);
        GameState g4(getGrid(), w, h, probOfPlace * PROB_4);
        result.emplace_back(g4);
    }

    setGrid(originalGrid);
    return result;
}

GameState::GameState(std::vector<int> grid, int width, int height, double probability) :
        Grid(std::move(grid), width, height), probability(probability) {}




