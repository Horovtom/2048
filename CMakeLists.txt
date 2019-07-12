cmake_minimum_required(VERSION 3.14)
project(2048)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        src/Game.cpp
        src/Grid.cpp
        )

add_executable(2048 src/main.cpp ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path
target_include_directories(2048
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )

set(TEST_LIB
        tests/Test.cpp
        tests/Test.h)

add_executable(test tests/runTests.cpp ${SOURCES} ${TEST_LIB})
target_include_directories(test
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include)