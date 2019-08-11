//
// Created by lactosis on 19.7.19.
//

#include <tests/Test.h>
#include <ai/minmax/GameState.h>
#include <ai/minmax/FullSearchPlayer.h>

bool containsState(const std::vector<GameState> &gameStates, const std::vector<int> &state, double probability) {
    for (GameState g : gameStates) {
        std::vector<int> curr = g.getGrid();
        if (curr == state)
            return g.probability == probability;
    }
    return false;
}

bool testStateGeneration1(Test &test) {
    bool chain = true;
    // 8 4 4
    // 2 2 0
    std::vector<int> grid({8, 4, 4, 2, 2, 0});
    GameState g(grid, 3, 2, 1.0);

    // Right move:
    // 0 8 8
    // 0 0 4
    std::vector<GameState> gameStates = g.getChildrenStates(RIGHT);
    std::vector<int> state({2, 8, 8, 0, 0, 4});
    test.assertTrue(containsState(gameStates, state, (1.0 / 3.0) * 0.90), "The result should contain this state!",
                    &chain);
    state = std::vector<int>({4, 8, 8, 0, 0, 4});
    test.assertTrue(containsState(gameStates, state, (1.0 / 3.0) * 0.10), "The result should contain this state!",
                    &chain);
    state = std::vector<int>({0, 8, 8, 2, 0, 4});
    test.assertTrue(containsState(gameStates, state, (1.0 / 3.0) * 0.90), "The result should contains this state!",
                    &chain);
    state = std::vector<int>({0, 8, 8, 4, 0, 4});
    test.assertTrue(containsState(gameStates, state, (1.0 / 3.0) * 0.10), "The result should contains this state!",
                    &chain);
    state = std::vector<int>({0, 8, 8, 0, 2, 4});
    test.assertTrue(containsState(gameStates, state, (1.0 / 3.0) * 0.90), "The result should contains this state!",
                    &chain);
    state = std::vector<int>({0, 8, 8, 0, 4, 4});
    test.assertTrue(containsState(gameStates, state, (1.0 / 3.0) * 0.10), "The result should contains this state!",
                    &chain);
    test.assertTrue(gameStates.size() == 6, "The result should contain only six states!", &chain);

    // DOWN move:
    // 8 4 0
    // 2 2 4
    g.setGrid(grid);
    gameStates = g.getChildrenStates(DOWN);
    state = std::vector<int>({8, 4, 2, 2, 2, 4});
    test.assertTrue(containsState(gameStates, state, 0.90), "The result should contain this state!", &chain);
    test.assertTrue(containsState(gameStates, {8, 4, 4, 2, 2, 4}, 0.10), "The result should contain this state!",
                    &chain);
    test.assertTrue(gameStates.size() == 2, "The result should contain only two states!", &chain);

    return chain;
}
