//
// Created by lactosis on 19.7.19.
//

#include <tests/Test.h>
#include "testGrid.cpp"
#include "testMinMax.cpp"

int main(int argc, char *argv[]) {
    Test test;
    // Grid tests
    test.registerTest(testGridReference, "Test of grid vector passing");
    test.registerTest(testMove1, "Test Move symmetrical");
    test.registerTest(testMove2, "Test Move asymmetrical");
    test.registerTest(testMovePossible, "Test Move Possible");
    test.registerTest(testCanMakeMove, "Test of canMakeMove function");

    // Minmax tests
    test.registerTest(testStateGeneration1, "Test of state generation function");

    test.run();
}