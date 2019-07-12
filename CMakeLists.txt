cmake_minimum_required(VERSION 3.14)
project(2048)

set(CMAKE_CXX_STANDARD 14)

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

add_executable(test tests/test.cpp ${SOURCES})
target_include_directories(test
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include)