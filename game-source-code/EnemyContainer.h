/**
 * @file EnemyContainer.h
 * @brief This file defines the EnemyContainer class, which manages a container of Enemy objects.
 *
 * The EnemyContainer class is responsible for adding, updating, and strategizing the behavior of Enemy objects.
 * It observes target and potential abductee positions and introduces new enemies into the container.
 */
#ifndef ENEMYCONTAINER_H
#define ENEMYCONTAINER_H

#include "Enemy.h"
#include "RandomGenerator.h"
#include "Timer.h"

/**
 * @class EnemyContainer
 * @brief A container class for managing Enemy objects.
 */
typedef vector<EnemyPtr> EnemyList;
typedef vector<EnemyPtr>::iterator EnemyIter;
class EnemyContainer
{
public:
    /**
     * @brief Constructs an EnemyContainer.
     */
    EnemyContainer();

    /**
     * @brief Adds an Enemy to the container.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    void add(double, double);

    /**
     * @brief Updates the EnemyContainer and its enemies.
     */
    void update();

    /**
     * @brief Sets the list of enemies for the container.
     * @param enemyList The list of enemies to set.
     */
    void setEnemyList(EnemyList);

    /**
     * @brief Retrieves the list of enemies from the container.
     * @return The list of enemies.
     */
    EnemyList getEnemyList();

    /**
     * @brief Observes the target position.
     * @param x The x-coordinate of the target.
     * @param y The y-coordinate of the target.
     */
    void observeTarget(double, double);

    /**
     * @brief Observes the potential abductee's position.
     * @param x The x-coordinate of the potential abductee.
     * @param y The y-coordinate of the potential abductee.
     */
    void observePotentialAbductee(double, double);

    /**
     * @brief Introduces a new enemy.
     */
    void introduceEnemy();

    /**
     * @brief Gets the current enemy count.
     * @return The current enemy count.
     */
    int getEnemyCount() const;

private:
    /**
     * @brief Removes dead enemies from the container.
     */
    void removeDeadEnemies();

    /**
     * @brief Strategizes and manages enemy behavior.
     */
    void strategise();

    /**
     * @brief Arms the enemy.
     */
    void armEnemy();

    /**
     * @brief Checks if there is any enemy on the abduct position.
     * @return True if an enemy is on the abduct position, otherwise false.
     */
    bool isAnyEnemyOnAbduct();

    /**
     * @brief Validates the position.
     * @param pos The position to validate.
     * @return True if the position is valid, otherwise false.
     */
    bool validPosition(int);

    EnemyList _enemyList;          ///< List of enemies.
    Timer _timer0;                 ///< Timer 0.
    Timer _timer1;                 ///< Timer 1.
    Timer _timer2;                 ///< Timer 2.
    RandomGenerator _selector;    ///< Random selector generator.
    RandomGenerator _randomGenerator; ///< Random generator.
    int _xTarget;                  ///< X-coordinate of the target.
    int _yTarget;                  ///< Y-coordinate of the target.
    int _xPotentialAbductee;       ///< X-coordinate of the potential abductee.
    int _yPotentialAbductee;       ///< Y-coordinate of the potential abductee.
    int _enemyCount;              ///< Current enemy count.
};

#endif // ENEMYCONTAINER_H