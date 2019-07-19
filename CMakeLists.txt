cmake_minimum_required(VERSION 3.14)
project(2048)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM gtkmm-3.0) # look into FindPkgConfig.cmake,
# it contains documentation
# Now the variables GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES
# contain what you expect

link_directories(
        ${GTKMM_LIBRARY_DIRS})

include_directories(
        ${GTKMM_INCLUDE_DIRS})


set(GAME_SOURCES
        src/game/logic/Game.cpp
        src/game/logic/Grid.cpp
        )

set(GRAPHICS_SOURCES
        src/game/Controller.cpp
        src/graphics/GameArea.cpp
        src/graphics/GameWindow.cpp
        )

set(AI_SOURCES
        src/ai/GameState.cpp)


add_executable(2048 src/main.cpp ${GAME_SOURCES} ${GRAPHICS_SOURCES} ${AI_SOURCES})

target_link_libraries(2048
        ${GTKMM_LIBRARIES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path
target_include_directories(2048
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )

# -------------- TESTS ------------------
set(TEST_SOURCES
        src/tests/Test.cpp
        )

add_executable(test src/tests/runTests.cpp ${GAME_SOURCES} ${AI_SOURCES} ${TEST_SOURCES})
target_include_directories(test
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include)
