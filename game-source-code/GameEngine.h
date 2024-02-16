/**
 * @file GameEngine.h
 * @brief This file defines the GameEngine class, which is responsible for managing the main game loop and state transitions.
 */
#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <SFML/Graphics.hpp>
#include "StateStack.h"

/**
 * @brief The main game engine class responsible for running the game loop.
 */
class GameEngine
{
public:
    /**
     * @brief Constructor for the GameEngine class.
     */
    GameEngine();

    /**
     * @brief Destructor for the GameEngine class.
     */
    ~GameEngine();

    /**
     * @brief Start the game and run the game loop.
     */
    void RunGame();

private:
    StateStack _myStack;     ///< The state stack used to manage game states.
    RenderWindow _window;    ///< The SFML window used for rendering.

    const Time _timePerFrame = seconds(1.f/30.f);  ///< The time per frame for updating the game.

    /**
     * @brief Process user input.
     */
    void ProcessInput();

    /**
     * @brief Update the game state.
     *
     * @param dt The elapsed time since the last frame.
     */
    void Update(Time dt);

    /**
     * @brief Draw the current game state.
     */
    void Draw();
};

#endif
