//
// Created by lactosis on 12.7.19.
//

#include "Grid.h"
#include <string>
#include <iostream>

typedef bool (*TestFunction)();
const std::string tabs = "    ";

bool assertTrue(bool test, const std::string& assertName, bool* assertionChain) {
    std::cout << std::endl;
    if (!test) {
        std::cerr << "Assertion failed: " << assertName << std::endl;
        *assertionChain = false;
    }

    return test;
}

bool testMove1() {
    bool chain = true;
    assertTrue(2 == 3, "This is an assertion that should fail!", &chain);
    return chain;
}

bool testMove2() {
    bool chain = true;
    assertTrue(2 == 2, "This assertion should be file", &chain);
    assertTrue(3 == 4, "This assertion should fail!", &chain);
    assertTrue(2 == 2, "Karel", &chain);
    return chain;
}

bool testMove3() {
    bool chain = true;
    assertTrue(1 == 1, "This shluld be fine", &chain);
    return chain;
}

bool runTest(TestFunction testFunction, const std::string& testName) {
    std::cout << tabs << "Running test: " << testName << "... ";
    bool testPassed = testFunction();

    if (!testPassed)
        std::cerr << tabs << "Test: " << testName << " failed! " << std::endl;
    else
        std::cout << "OK" << std::endl;

    return testPassed;
}

int main(int argc, char *argv[]) {
    bool success = true;
    success = success && runTest(testMove1, "testMove1");
    success = success && runTest(testMove2, "testMove2");
    success = success && runTest(testMove3, "testMove3");

    if (!success) {
        std::cerr << "There were some tests that did go wrong!" << std::endl;
        return 1;
    } else {
        std::cout << "All tests passed :)" << std::endl;
        return 0;
    }
}
