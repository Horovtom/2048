#include "Game.h"
#include <iostream>
#include "Direction.h"

Game::Game() {
    std::cout << "I am in the constructor of Game" << std::endl;
}

void Game::init() {
    std::cout << "Initializing game" << std::endl;
}

void Game::run() {
    std::cout << "Running game" << std::endl;
}