//
// Created by lactosis on 12.7.19.
//

#include "Game.h"
#include <iostream>
#include "Direction.h"

Game::Game(int width, int height) : w(width), h(height), grid(width, height) {
    std::cout << "I am in the constructor of Game with w: " << w << ", h: " << h << std::endl;
}

void Game::init() {
    std::cout << "Initializing game" << std::endl;
}

void Game::run() {
    std::cout << "Running game" << std::endl;
}