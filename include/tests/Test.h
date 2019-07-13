//
// Created by lactosis on 12.7.19.
//

#ifndef INC_2048_TEST_H
#define INC_2048_TEST_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>


class Test {
public:
    typedef bool (*TestFunction)(Test &t);

    /**
     * An assert function that evaluates an expression and fills assertionChain with false if needed.
     * @param test An expression to be evaluated
     * @param assertName A string that should be displayed if this assert fails.
     * @param assertionChain This reference will be set to false if this assert fails
     * @return Whether the assert failed
     */
    bool assertTrue(bool test, const std::string &assertName, bool *assertionChain = nullptr);

    /**
     * Runs all registered tests
     * @return Whether all tests passed
     */
    bool run();

    /**
     * Registers a testing function in this class.
     * @param test Function that contains a test.
     * @param testName Description of the test.
     */
    void registerTest(TestFunction test, const std::string &testName);

private:
    /**
     * This will run a function reference and display appropriate messages to the console
     * @param testFunction A function pointer that is to be run
     * @param testName A name of the test to be displayed in the console.
     * @return Whether the test had passed.
     */
    bool runTest(TestFunction testFunction, const std::string &testName);

    /**
     * Temporarily disables stdout, such that we can catch everything that goes there to our tempCout stream.
     */
    void disableCout();

    /**
     * Enables stdout back and writes everything that we caught into tempCout stream
     */
    void enableAndWriteOutput(const std::string &prefix);

    /**
     * A vector of tests that are registered in this class.
     */
    std::vector<TestFunction> tests;

    std::vector<std::string> testNames;

    static const std::string tabs;

    /**
     * This holds a reference to the original cout stream
     */
    std::streambuf *oldCout;

    /**
     * This holds all data written to cout when we have it disabled
     */
    std::stringstream tempCout;

    /**
     * Whether the cout stream has been disabled.
     */
    bool disabledCout = false;
};


#endif //INC_2048_TEST_H
