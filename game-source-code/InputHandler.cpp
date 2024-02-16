#include "InputHandler.h"

/**
 * @brief Get the custom Button corresponding to a given SFML keyboard key.
 *
 * This function maps an SFML keyboard key to a custom Button type. It's used to convert
 * keyboard input into a more abstract representation for your game's logic.
 *
 * @param key The SFML keyboard key to map to a Button.
 * @return The mapped Button for the given key.
 */
Button InputHandler::getInput(sf::Keyboard::Key key)
{
    switch(key)
    {
    case sf::Keyboard::Up:
        return Button::UP;
        break;
    case sf::Keyboard::Down:
        return Button::DOWN;
        break;
    case sf::Keyboard::Left:
         return Button::LEFT;
        break;
    case sf::Keyboard::Right:
         return Button::RIGHT;
        break;
    case sf::Keyboard::Space:
        return Button::SPACE;
        break;
    default:
        return Button::NONE;
        ;
    }
}