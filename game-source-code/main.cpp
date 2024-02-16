/**
 * @file main.cpp
 * @brief Entry point for the game application.
 */

#include "GameEngine.h"

int main()
{
    auto myGame = GameEngine{};
    myGame.RunGame();
    return 0;
}
