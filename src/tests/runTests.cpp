//
// Created by lactosis on 12.7.19.
//

#include <game/logic/Grid.h>
#include <tests/Test.h>
#include <string>
#include <iostream>

/**
 * Tests two vectors of grid tiles for feasibility
 * @param got The vector we got from the move
 * @param expected The vector we expected to get after the move. All empty tiles should be marked with 0. This function will allow one added tile to one of these.
 * @param nameOfCheck The string that should be displayed as the name, if the check fails.
 * @return Whether the move was correct
 */
bool checkAfterMove(Test &test, std::vector<int> got, std::vector<int> expected, std::string nameOfCheck) {
    bool chain = true;
    test.assertTrue(got.size() == expected.size(),
                    std::string(nameOfCheck).append(" - The grid size changed after move!"), &chain);

    bool didChange = false;
    for (int i = 0; i < expected.size(); ++i) {
        if (expected.at(i) == 0 && got.at(i) != 0) {
            test.assertTrue(!didChange,
                            std::string(nameOfCheck).append(" - There were multiple added tiles in the resulting grid"),
                            &chain);
            didChange = true;
            test.assertTrue(got.at(i) == 2 || got.at(i) == 4,
                            std::string(nameOfCheck).append(" - Tile added had invalid value: ").append(
                                    std::to_string(got.at(i))),
                            &chain);
        } else
            test.assertTrue(expected.at(i) == got.at(i),
                            std::string(nameOfCheck).append(" - Result of the move was not correct!"),
                            &chain);
    }

    test.assertTrue(didChange, std::string(nameOfCheck).append(" - There was no tile added after the turn was made!"),
                    &chain);
    return chain;
}

bool checkDirectionsMoves(
        Test &test,
        std::vector<int> *originalGrid, int width, int height,
        std::vector<int> *leftGrid,
        std::vector<int> *rightGrid,
        std::vector<int> *upGrid,
        std::vector<int> *downGrid) {
    bool chain = true;
    if (originalGrid == nullptr)
        return chain;

    std::cout << "--Testing LEFT--" << std::endl;
    Grid g(*originalGrid, width, height);
    if (leftGrid != nullptr) {
        test.assertTrue(g.makeTurn(LEFT), "The LEFT turn should be possible", &chain);
        test.assertTrue(checkAfterMove(test, g.getGrid(), *leftGrid, "LEFT move"), "Result of LEFT move was invalid",
                        &chain);
        g.setGrid(*originalGrid);
    } else {
        test.assertTrue(!g.makeTurn(LEFT), "The LEFT turn should NOT be possible", &chain);
    }

    std::cout << "--Testing RIGHT--" << std::endl;
    if (rightGrid != nullptr) {
        test.assertTrue(g.makeTurn(RIGHT), "The RIGHT turn should be possible", &chain);
        test.assertTrue(checkAfterMove(test, g.getGrid(), *rightGrid, "RIGHT move"), "Result of RIGHT move was invalid",
                        &chain);
        g.setGrid(*originalGrid);
    } else {
        test.assertTrue(!g.makeTurn(RIGHT), "The RIGHT turn should NOT be possible", &chain);
    }

    std::cout << "--Testing UP--" << std::endl;
    if (upGrid != nullptr) {
        test.assertTrue(g.makeTurn(UP), "The UP turn should be possible", &chain);
        test.assertTrue(checkAfterMove(test, g.getGrid(), *upGrid, "UP move"), "Result of UP move was invalid",
                        &chain);
        g.setGrid(*originalGrid);
    } else {
        test.assertTrue(!g.makeTurn(UP), "The UP turn should NOT be possible", &chain);
    }

    std::cout << "--Testing DOWN--" << std::endl;
    if (downGrid != nullptr) {
        test.assertTrue(g.makeTurn(DOWN), "The DOWN turn should be possible", &chain);
        test.assertTrue(checkAfterMove(test, g.getGrid(), *downGrid, "DOWN move"), "Result of DOWN move was invalid",
                        &chain);
        g.setGrid(*originalGrid);
    } else {
        test.assertTrue(!g.makeTurn(DOWN), "The DOWN turn should NOT be possible", &chain);
    }

    return chain;
}

bool testMove1(Test &test) {
    std::vector<int> grid({0, 0, 2, 0, 8, 0, 8, 0, 2, 4, 4, 0, 4, 32, 2, 0});
    std::vector<int> left({2, 0, 0, 0, 16, 0, 0, 0, 2, 8, 0, 0, 4, 32, 2, 0});
    std::vector<int> right({0, 0, 0, 2, 0, 0, 0, 16, 0, 0, 2, 8, 0, 4, 32, 2});
    std::vector<int> up({8, 4, 2, 0, 2, 32, 8, 0, 4, 0, 4, 0, 0, 0, 2, 0});
    return checkDirectionsMoves(test, &grid, 4, 4, &left, &right, &up, nullptr);
}

bool testMove2(Test &test) {
    std::vector<int> grid({2, 2, 4, 4, 128, 4, 2, 2, 16, 16, 8, 8, 8, 8, 64, 16, 8, 16, 32, 256});
    std::vector<int> left({4, 8, 128, 0, 0, 4, 4, 32, 0, 0, 16, 16, 64, 0, 0, 16, 8, 16, 32, 256});
    std::vector<int> right({0, 0, 4, 8, 128, 0, 0, 4, 4, 32, 0, 0, 16, 16, 64, 16, 8, 16, 32, 256});
    std::vector<int> up({2, 4, 4, 4, 128, 4, 16, 2, 16, 16, 8, 0, 8, 8, 64, 16, 0, 16, 32, 256});
    std::vector<int> down({2, 0, 4, 4, 128, 4, 0, 2, 16, 16, 8, 4, 8, 8, 64, 16, 16, 16, 32, 256});
    return checkDirectionsMoves(test, &grid, 5, 4, &left, &right, &up, &down);
}

bool testMovePossible(Test &test) {
    bool chain = true;
    std::vector<int> grid({4, 8, 4, 8, 4, 8});
    chain = checkDirectionsMoves(test, &grid, 3, 2, nullptr, nullptr, nullptr, nullptr) && chain;
    std::vector<int> grid2({4, 8, 4, 4, 16, 32});
    std::vector<int> upGrid({8, 8, 4, 0, 16, 32});
    std::vector<int> downGrid({0, 8, 4, 8, 16, 32});
    chain = checkDirectionsMoves(test, &grid2, 3, 2, nullptr, nullptr, &upGrid, &downGrid) && chain;

    return chain;
}

bool testCanMakeMove(Test &test) {
    bool chain = true;
    std::vector<int> grid({4, 8, 4, 8, 4, 8});
    std::vector<int> grid2({4, 8, 4, 4, 16, 32});

    Grid g(grid, 3, 2);
    test.assertTrue(!g.canMakeTurn(), "This grid should not be able to make a move", &chain);
    g.setGrid(grid2);
    test.assertTrue(g.canMakeTurn(), "This grid should be able to make a move", &chain);

    return chain;
}

bool testGridReference(Test &test) {
    bool chain = true;
    std::vector<int> grid({0, 0, 0, 0, 0, 0});
    Grid g(grid, 3, 2);
    grid.at(0) = 3;
    test.assertTrue(g.getGrid().at(0) == 0,
                    "The vector passed as constructor argument was saved as a reference. It should not!", &chain);
    g.setGrid(grid);
    grid.at(0) = 0;
    test.assertTrue(g.getGrid().at(0) == 3,
                    "The vector passed in setGrid function was saved as a reference. It should not!", &chain);
    auto l = g.getGrid();
    l.at(1) = 4;
    test.assertTrue(g.getGrid().at(1) == 0,
                    "The vector we got in getGrid function was passed as a reference. It should not!", &chain);
    test.assertTrue(g.getGrid().size() == 6, "The vector size changed!", &chain);

    return chain;
}


int main(int argc, char *argv[]) {
    Test test;
    test.registerTest(testGridReference, "Test of grid vector passing");
    test.registerTest(testMove1, "Test Move symmetrical");
    test.registerTest(testMove2, "Test Move asymmetrical");
    test.registerTest(testMovePossible, "Test Move Possible");
    test.registerTest(testCanMakeMove, "Test of canMakeMove function");
    test.run();
}
