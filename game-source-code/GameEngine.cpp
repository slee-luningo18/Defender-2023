/**
 * @file GameEngine.cpp
 * @brief Implementation of the GameEngine class.
 */

#include "GameEngine.h"
#include "GameStates.h"
#include "Menu.h"
#include "Options.h"
#include "Help.h"
#include "Exit.h"
#include "StateStack.h"
#include "SplashScreen.h"

GameEngine::GameEngine()
{
    // Create the game window
    _window.create(VideoMode(900, 700), "Defender");
    _window.setFramerateLimit(30);

    // Register different game states with the state stack
    _myStack.registerState(States::SplashScreen);
    _myStack.registerState(States::Menu);
    _myStack.registerState(States::Options);
    _myStack.registerState(States::Help);
    _myStack.registerState(States::Game);
    _myStack.registerState(States::Exit);
    _myStack.registerState(States::EndGame);

    // Push the initial state to start the game with the splash screen
    _myStack.pushState(States::SplashScreen);
}

void GameEngine::ProcessInput()
{
    Event event;
    while (_window.pollEvent(event))
    {
        // Pass the event to the state stack to handle
        _myStack.handleEvent(event, _window);
    }
}

void GameEngine::Draw()
{
    // Draw the active state on the game window
    _myStack.draw(_window);
}

void GameEngine::Update(Time dt)
{
    // Update game states with the elapsed time
    _myStack.update(dt);
}

void GameEngine::RunGame()
{
    Clock clock;
    Time timeSinceLastUpdate = Time::Zero;

    while (_window.isOpen())
    {
        timeSinceLastUpdate += clock.restart();

        while (timeSinceLastUpdate > _timePerFrame)
        {
            timeSinceLastUpdate -= _timePerFrame;

            // Process user input and update the game state
            ProcessInput();
            Update(_timePerFrame);
        }

        // Draw the game state on the window
        Draw();
    }
}

GameEngine::~GameEngine() {}