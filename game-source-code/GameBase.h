/**
 * @file GameBase.h
 * @brief Declaration of the GameBase class.
 */

#ifndef GAMEBASE_H
#define GAMEBASE_H

#include "InputHandler.h"
#include "EnemyContainer.h"
#include "Player.h"
#include "Humanoids.h"
#include "FuelTanks.h"
#include "Timer.h"
#include "Utils.h"
#include "CollisionsDetector.h"
#include "RandomGenerator.h"

/**
 * @class GameBase
 * @brief Represents the game's core logic.
 */
class GameBase
{
public:
    /**
     * @brief Constructs a GameBase object.
     */
    GameBase();

    /**
     * @brief Get the player character.
     * @return The player object.
     */
    Player getPlayer();

    /**
     * @brief Get the container of enemies.
     * @return The container of enemy objects.
     */
    EnemyContainer getEnemies();

    /**
     * @brief Get the container of humanoids.
     * @return The container of humanoid objects.
     */
    Humanoids getHumanoids();
    FuelTanks getFuelTanks();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void shoot();

    /**
     * @brief Update the game state.
     */
    void gameUpdate();

    /**
     * @brief Check if the game is over.
     * @return True if the game is over, otherwise false.
     */
    bool isGameOver();

    /**
     * @brief Get the current score.
     * @return The current score.
     */
    int getScore()const;

    /**
     * @brief Check if the player has won the game.
     * @return True if the player has won, otherwise false.
     */
    bool hasWon();

private:
    Player _player;                    /**< The player character. */
    EnemyContainer _enemies;           /**< Container for enemies. */
    Humanoids _humanoids;              /**< Container for humanoids. */
    CollisionsDetector _collisionsDetector; /**< Detector for collisions between game objects. */
    Timer _timer;//Timing
    FuelTanks _fuelTank;//Fuel tanks
    /**
     * @brief Choose a target for humanoids to abduct.
     */
    void chooseHumanoidTarget();
    void introduceFuel();//Introduce Fuel
    int _humanoidTarget; /**< Index of the current humanoid target. */
};
#endif // GAMEBASE_H