//
// Created by lactosis on 12.7.19.
//

#include <tuple>
#include "Test.h"

const std::string Test::tabs = "    ";

bool Test::assertTrue(bool test, const std::string &assertName, bool *assertionChain) {
    if (!test) {
        enableAndWriteOutput(tabs + tabs + tabs);
        std::cout << " *  " << Test::tabs << "Assertion failed: " << assertName << std::endl;
        disableCout();
        *assertionChain = false;
    }

    return test;
}

bool Test::runTest(TestFunction testFunction, const std::string &testName) {
    std::cout << tabs << "----------------------------------" << std::endl;
    std::cout << tabs << "Running test: " << testName << " " << std::endl;

    std::cout << tabs << tabs << "Test standard output: " << std::endl;
    disableCout();
    bool testPassed = false;
    try {
        testPassed = testFunction(*this);
    } catch (std::exception &e) {
        enableAndWriteOutput(tabs + tabs + tabs);
        std::cout.flush();
        std::cout << " ** " + tabs + tabs << "Exception occurred while executing test! " << e.what() << std::endl;
    }

    enableAndWriteOutput(tabs + tabs + tabs);

    if (!testPassed)
        std::cout << tabs << "Failed! " << std::endl;
    else
        std::cout << tabs << "OK" << std::endl;
    std::cout << tabs << "----------------------------------" << std::endl << std::endl;
    return testPassed;
}

bool Test::run() {
    std::cout << "Running tests..." << std::endl;
    int failed = 0;

    for (int i = 0; i < tests.size(); ++i) {
        failed += !runTest(tests.at(i), testNames.at(i));
    }

    if (failed != 0) {
        std::cout << "TESTS FAILED: " << failed << std::endl;
        return true;
    } else {
        std::cout << "All tests passed :)" << std::endl;
        return false;
    }
}

void Test::registerTest(Test::TestFunction test, const std::string &testName) {
    tests.emplace_back(test);
    testNames.emplace_back(testName);
}

void Test::disableCout() {
    if (disabledCout) return;
    oldCout = std::cout.rdbuf(tempCout.rdbuf());
    disabledCout = true;
}

void Test::enableAndWriteOutput(const std::string &prefix) {
    if (!disabledCout) return;
    std::cout.rdbuf(oldCout);
    std::string line;
    while (std::getline(tempCout, line)) {
        std::cout << prefix << line << std::endl;
    }
    tempCout.clear();
    disabledCout = false;
}

