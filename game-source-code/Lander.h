/**
 * @file Lander.h
 * @brief Defines the Lander class for representing a lander object in the game.
 */

#ifndef LANDER_H
#define LANDER_H
#include "GameObject.h"
#include "RandomGenerator.h"
#include "Humanoids.h"

/**
 * @class Lander
 * @brief Represents a lander object in the game.
 *
 * This class extends the GameObject class and provides functionality
 * for a lander's movement, targeting, observing, and abduction of humanoids.
 */
class Lander : public GameObject
{
public:
    /**
     * @brief Constructor for the Lander class.
     * @param x The initial x-coordinate of the lander.
     * @param y The initial y-coordinate of the lander.
     */
    Lander(double, double);

    /**
     * @brief Set the target coordinates for the lander.
     * @param x The x-coordinate of the target.
     * @param y The y-coordinate of the target.
     */
    void setTarget(double, double);

    /**
     * @brief Observe a location.
     * @param x The x-coordinate of the location.
     * @param y The y-coordinate of the location.
     */
    void observe(double, double);

    /**
     * @brief Abduct a humanoid.
     * @param abductee A shared pointer to the humanoid to be abducted.
     */
    void abductHumanoid(GameObjectPtr);

    /**
     * @brief Get the humanoid that has been abducted.
     * @return The abducted humanoid.
     */
    Humanoids getAbductee();

    /**
     * @brief Move the lander based on its state and direction.
     */
    virtual void Move();

private:
    /**
     * @brief Move the lander in attack mode.
     */
    void moveInAttack();

    /**
     * @brief Move the lander in abduction mode.
     */
    void moveInAbduct();

    /**
     * @brief Move the lander in escape mode.
     */
    void moveInEscape();

    /**
     * @brief Move the lander to the left.
     */
    void moveLeft();

    /**
     * @brief Move the lander to the right.
     */
    void moveRight();

    /**
     * @brief Move the lander downwards.
     */
    void moveDown();

    /**
     * @brief Move the lander upwards.
     */
    void moveUp();

    /**
     * @brief Move the lander to the upper-left direction.
     */
    void moveLeftUp();

    /**
     * @brief Move the lander to the lower-left direction.
     */
    void moveLeftDown();

    /**
     * @brief Move the lander to the upper-right direction.
     */
    void moveRightUp();

    /**
     * @brief Move the lander to the lower-right direction.
     */
    void moveRightDown();

    double _xTarget;
    double _yTarget;
    double _gradient;
    double _yIntercept;
    Humanoids _abductee;
    RandomGenerator _selector;
};

#endif // LANDER_H
