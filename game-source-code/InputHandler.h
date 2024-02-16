/**
 * @file InputHandler.h
 * @brief Defines the InputHandler class responsible for handling keyboard input.
 */

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <SFML/Window.hpp>
#include "Utils.h"

/**
 * @class InputHandler
 * @brief Handles keyboard input and maps it to a custom Button type.
 */
class InputHandler
{
public:
/**
     * @brief Get the custom Button corresponding to a given SFML keyboard key.
     * @param key The SFML keyboard key to map to a Button.
     * @return The mapped Button for the given key.
     */
    Button getInput(sf::Keyboard::Key);
};
#endif // INPUTHANDLER_H