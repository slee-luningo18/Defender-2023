#include "EnemyContainer.h"

/**
 * @brief Constructor for the EnemyContainer class.
 * Initializes the container with initial values and starts timers.
 */
EnemyContainer::EnemyContainer()
{
    _xTarget = 0;
    _yTarget = 0;
    _xPotentialAbductee = 0;
    _yPotentialAbductee = 0;
    _enemyCount = 1;
    _timer0.start();
    _timer1.start();
    _timer2.start();
    add(16, 192);
}

/**
 * @brief Observes the target's position.
 * @param x The X-coordinate of the target.
 * @param y The Y-coordinate of the target.
 */
void EnemyContainer::observeTarget(double x, double y)
{
    _xTarget = x;
    _yTarget = y;
}

/**
 * @brief Observes the potential abductee's position.
 * @param x The X-coordinate of the potential abductee.
 * @param y The Y-coordinate of the potential abductee.
 */
void EnemyContainer::observePotentialAbductee(double x, double y)
{
    _xPotentialAbductee = x;
    _yPotentialAbductee = y;
}

/**
 * @brief Introduces a new enemy into the container under certain conditions.
 */
void EnemyContainer::introduceEnemy()
{
    auto x = 0;
    auto y = 0;
    if (_timer2.readTime() >= 4.5 && static_cast<int>(getEnemyList().size()) != 4 && _enemyCount != 8)
    {
        do
        {
            x = _randomGenerator.random_int(16, 880);
        } while (!validPosition(x));

        do
        {
            y = _randomGenerator.random_int(96, 572);
        } while (!validPosition(y));
        add(x, y);
        _enemyCount++;
        _timer2.start();
    }
}

/**
 * @brief Arms an enemy to shoot the target under certain conditions.
 */
void EnemyContainer::armEnemy()
{
    if (_timer1.readTime() >= 2.0 && !(_enemyList.empty()))
    {
        int trial = 0;
        do
        {
            int choice = _selector.random_int(0, static_cast<int>(_enemyList.size() - 1));
            if ((_enemyList.at(choice))->getLander().getObjective() == Objective::ATTACK)
            {
                (_enemyList.at(choice))->shootTarget(_xTarget, _yTarget);
                break;
            }
            trial++;
        } while (trial != 3);
        _timer1.start();
    }
}

/**
 * @brief Checks if any enemy is on the abduct objective.
 * @return True if at least one enemy has the abduct or escape objective, false otherwise.
 */
bool EnemyContainer::isAnyEnemyOnAbduct()
{
    for (EnemyIter iter = begin(_enemyList); iter != end(_enemyList); iter++)
    {
        if ((*iter)->getLander().getObjective() == Objective::ABDUCT || (*iter)->getLander().getObjective() == Objective::ESCAPE)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Checks if a position is valid (even X-coordinate).
 */
bool EnemyContainer::validPosition(int x)
{
    if (x % 2 == 0)
        return true;
    else
        return false;
}

/**
 * @brief Sets the enemy list of the container.
 * @param enemyList The new enemy list.
 */
void EnemyContainer::setEnemyList(EnemyList enemyList)
{
    _enemyList = enemyList;
}

/**
 * @brief Retrieves the enemy list of the container.
 * @return The enemy list.
 */
EnemyList EnemyContainer::getEnemyList()
{
    return _enemyList;
}

/**
 * @brief Gets the count of enemies in the container.
 * @return The enemy count.
 */
int EnemyContainer::getEnemyCount() const
{
    return _enemyCount;
}

/**
 * @brief Removes dead enemies from the container.
 */
void EnemyContainer::removeDeadEnemies()
{
    EnemyList tempList;
    for (EnemyIter iter = begin(_enemyList); iter != end(_enemyList); iter++)
    {
        if ((*iter)->isAlive())
        {
            tempList.push_back(*iter);
        }
    }
    _enemyList.clear();
    _enemyList = tempList;
}

/**
 * @brief Strategizes the enemy behavior under certain conditions.
 */
void EnemyContainer::strategise()
{
    if (_timer0.readTime() >= 8.0 && !(_enemyList.empty()) && !isAnyEnemyOnAbduct())
    {
        int trial = 0;
        do
        {
            int choice = _selector.random_int(0, static_cast<int>(_enemyList.size() - 1));
            if ((_enemyList.at(choice))->getLander().getObjective() == Objective::ATTACK)
            {
                (_enemyList.at(choice))->changeStrategy(Objective::ABDUCT);
                break;
            }
            trial++;
        } while (trial != 3);
        _timer0.start();
    }
}

/**
 * @brief Adds an enemy to the container.
 * @param x The X-coordinate of the enemy.
 * @param y The Y-coordinate of the enemy.
 */
void  EnemyContainer::add(double x, double y)
{
    EnemyPtr enemy = std::make_shared<Enemy>(x, y);
    if (static_cast<int>(_enemyList.size()) < 4)
    {
        enemy->observeTarget(_xTarget, _yTarget);
        enemy->setEnemyTarget(_xTarget, _yTarget);
        enemy->changeStrategy(Objective::ATTACK);
        _enemyList.push_back(enemy);
    }
}

/**
 * @brief Updates the enemy container.
 */
void EnemyContainer::update()
{
    auto x = 0;
    auto y = 0;
    armEnemy();
    for (EnemyIter iter = begin(_enemyList); iter != end(_enemyList); iter++)
    {
        (*iter)->updateEnemy();
        if ((*(iter))->getLander().getObjective() == Objective::ABDUCT)
        {
            (*iter)->setEnemyTarget(_xPotentialAbductee, _yPotentialAbductee);
        }
        else
        {
            (*iter)->setEnemyTarget(_xTarget + x, _yTarget + y);
            x += 32;
            y += 32;
        }
    }
    removeDeadEnemies();
    strategise();
}