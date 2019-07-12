//
// Created by lactosis on 12.7.19.
//

#include "Grid.h"
#include "Test.h"
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
    test.assertTrue(got.size() == expected.size(), nameOfCheck.append(" - The grid size changed after move!"), &chain);

    bool didChange = false;
    for (int i = 0; i < expected.size(); ++i) {
        if (expected.at(i) == 0 && got.at(i) != 0) {
            test.assertTrue(!didChange, nameOfCheck.append(" - There were multiple added tiles in the resulting grid"),
                            &chain);
            didChange = true;
            test.assertTrue(got.at(i) == 2 || got.at(i) == 4,
                            nameOfCheck.append(" - Tile added had invalid value: ").append(std::to_string(got.at(i))),
                            &chain);
        } else
            test.assertTrue(expected.at(i) == got.at(i), nameOfCheck.append(" - Result of the move was not correct!"),
                            &chain);
    }

    test.assertTrue(didChange, nameOfCheck.append(" - There was no tile added after the turn was made!"), &chain);
    return chain;
}

bool testMove1(Test &test) {
    bool chain = true;
    //  0   0   2   0
    //  8   0   8   0
    //  2   4   4   0
    //  4   32  2   0
    std::vector<int> grid({0, 0, 2, 0, 8, 0, 8, 0, 2, 4, 4, 0, 4, 32, 2, 0});

    Grid g(grid, 4, 4);
    test.assertTrue(g.makeTurn(LEFT),
                    "The LEFT turn should be possible.", &chain);
    test.assertTrue(
            checkAfterMove(test, g.getGrid(), std::vector<int>({2, 0, 0, 0, 16, 0, 0, 0, 2, 8, 0, 0, 4, 32, 2, 0}),
                           "LEFT move"),
            "The result of the LEFT move was not correct!", &chain);
    g.setGrid(grid);

    test.assertTrue(!g.makeTurn(RIGHT),
                    "The RIGHT turn should be possible", &chain);
    test.assertTrue(
            checkAfterMove(test, g.getGrid(), std::vector<int>({0, 0, 0, 2, 0, 0, 0, 16, 0, 0, 2, 8, 0, 4, 32, 2}),
                           "RIGHT move"),
            "The result of the RIGHT move was not correct!", &chain);
    g.setGrid(grid);

    test.assertTrue(g.makeTurn(UP),
                    "The UP turn should be possible", &chain);
    test.assertTrue(
            checkAfterMove(test, g.getGrid(), std::vector<int>({8, 4, 2, 0, 2, 32, 8, 0, 4, 0, 4, 0, 0, 0, 2, 0}),
                           "UP move"),
            "The result of the UP move was not correct!", &chain);
    g.setGrid(grid);

    test.assertTrue(!g.makeTurn(DOWN),
                    "The DOWN turn should NOT be possible", &chain);
    test.assertTrue(g.getGrid() == grid,
                    "The grid should not change after an impossible move!", &chain);
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
    test.registerTest(testMove1, "Test Move 1");
    test.run();
}
