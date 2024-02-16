/**
 * @file GameStates.h
 * @brief Contains the definition of the game states enumeration.
 */

#ifndef GAMESTATES_H
#define GAMESTATES_H

/**
 * @enum States
 * @brief Enumeration representing various game states.
 */
enum class States
{
    SplashScreen, ///< The splash screen state.
    Menu,        ///< The main menu state.
    Options,     ///< The options menu state.
    Help,        ///< The help state.
    Game,        ///< The gameplay state.
    Exit,        ///< The state for exiting the game.
    EndGame      ///< The state for ending the game.
};

#endif