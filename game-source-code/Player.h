/**
 * @file Player.h
 * @brief Header file for the Player class.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "SpaceShip.h"
#include "LaserShots.h"
#include "Fuel.h"
/**
 * @class Player
 * @brief A class representing the player in the game.
 */
class Player
{
public:
    /**
     * @brief Constructor for the Player class.
     * @param x The initial X-coordinate of the player.
     * @param y The initial Y-coordinate of the player.
     */
    Player(double, double);

    /**
     * @brief Get the player's spaceship.
     * @return A reference to the player's spaceship.
     */
    SpaceShip& getSpaceShip();

    Fuel& getFuel();//Fuel for the player

    /**
     * @brief Get the player's laser shots.
     * @return The player's laser shots.
     */
    LaserShots getLaserShots();

    /**
     * @brief Check if the player is alive.
     * @return True if the player is alive, false otherwise.
     */
    bool isAlive();

    /**
     * @brief Rescue a lander and associate it with the player.
     * @param abductee A pointer to the lander object to be rescued.
     */
    void rescueLander(GameObjectPtr);

    /**
     * @brief Update the player's status and objects.
     */
    void playerUpdate();

    /**
     * @brief Handle player input based on the provided button.
     * @param button The button to handle.
     */
    void handlePlayerInput(Button);
    void shoot();

private:
    SpaceShip _player; ///< The player's spaceship.
    LaserShots _laserShots; ///< The player's laser shots.
    Fuel _fuel;///< The player's fuel.
};
#endif // PLAYER_H