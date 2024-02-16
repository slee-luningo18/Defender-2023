/**
 * @file Enemy.h
 * @brief This file defines the Enemy class for representing enemy objects in the game.
 *
 * The Enemy class represents an enemy object in the game, with functions and attributes for
 * managing its Lander, Missiles, strategies, targeting, and behavior. This class is an integral
 * part of the game's enemy behavior and interactions.
 */
#ifndef ENEMY_H
#define ENEMY_H

#include "Lander.h"
#include "Missiles.h"
#include "Utils.h"

/**
 * @brief Represents an enemy object in the game.
 */
class Enemy
{
public:
    /**
     * @brief Constructor for the Enemy class.
     * @param x The initial X-coordinate of the enemy.
     * @param y The initial Y-coordinate of the enemy.
     */
    Enemy(double, double);

    /**
     * @brief Gets the reference to the enemy's Lander.
     * @return A reference to the Lander.
     */
    Lander& getLander();

    /**
     * @brief Gets the enemy's Missiles.
     * @return The Missiles object.
     */
    Missiles getMissiles();

    /**
     * @brief Checks if the enemy is alive.
     * @return True if the enemy is alive, false if not.
     */
    bool isAlive() const;

    /**
     * @brief Sets the target for the enemy.
     * @param x The X-coordinate of the target.
     * @param y The Y-coordinate of the target.
     */
    void setEnemyTarget(double, double);

    /**
     * @brief Observes the target's position.
     * @param x The X-coordinate of the target.
     * @param y The Y-coordinate of the target.
     */
    void observeTarget(double, double);

    /**
     * @brief Changes the enemy's strategy.
     * @param objective The new strategy (Objective) for the enemy.
     */
    void changeStrategy(Objective);

    /**
     * @brief Shoots a target.
     * @param x The X-coordinate of the target to be shot.
     * @param y The Y-coordinate of the target to be shot.
     */
    void shootTarget(double, double);

    /**
     * @brief Abducts a Lander.
     * @param landerPtr A pointer to the GameObject representing the Lander to be abducted.
     */
    void abductLander(GameObjectPtr);

    /**
     * @brief Updates the enemy's state and behavior.
     */
    void updateEnemy();

private:
    Lander _lander;     /**< The Lander controlled by the enemy. */
    Missiles _missiles; /**< The Missiles fired by the enemy. */
};

typedef std::shared_ptr<Enemy> EnemyPtr;

#endif // ENEMY_H
