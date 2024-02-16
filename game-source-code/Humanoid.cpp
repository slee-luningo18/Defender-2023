#include "Humanoid.h"

/**
 * @brief Constructs a Humanoid object with the given initial position.
 *
 * Initializes the Humanoid object with its initial position, status, heading, speed, and timer.
 *
 * @param x The initial X-coordinate of the humanoid.
 * @param y The initial Y-coordinate of the humanoid.
 */
Humanoid::Humanoid(double x, double y) : GameObject(x, y)
{
    setStatus(Status::FREE);
    setHeading(Heading::LEFTHEADING);
    _objectSpeed = _objectSpeed * 0.125;
    _flag = true;
    _timer.start();
}

/**
 * @brief Moves the humanoid character upwards.
 *
 * Moves the humanoid character upwards by decreasing its Y-coordinate position.
 * If the Y-coordinate becomes too low, the character's state is set to DEAD.
 */
void Humanoid::moveUp()
{
    if (_yPosition > 92)
        _yPosition -= _objectSpeed;
    else
        setState(ObjectState::DEAD);
}

/**
 * @brief Moves the humanoid character to the left.
 *
 * Moves the humanoid character to the left by decreasing its X-coordinate position.
 * If the X-coordinate becomes too low, the character's heading is set to LEFTHEADING.
 */
void Humanoid::moveLeft()
{
    if (_xPosition > 0)
    {
        _xPosition -= _objectSpeed;
        setHeading(Heading::LEFTHEADING);
    }
}

/**
 * @brief Moves the humanoid character to the right.
 *
 * Moves the humanoid character to the right by increasing its X-coordinate position.
 * If the X-coordinate becomes too high, the character's heading is set to RIGHTHEADING.
 */
void Humanoid::moveRight()
{
    if (_xPosition < 880)
    {
        _xPosition += _objectSpeed;
        setHeading(Heading::RIGHTHEADIND);
    }
}

/**
 * @brief Moves the humanoid character downwards.
 *
 * Moves the humanoid character downwards by increasing its Y-coordinate position.
 * If the Y-coordinate becomes too high, the character's state is set to DEAD.
 */
void Humanoid::moveDown()
{
    if (_yPosition < 668)
        _yPosition += _objectSpeed;
    else
        setState(ObjectState::DEAD);
}

/**
 * @brief Implements movement behavior for a free humanoid character.
 *
 * This method provides the movement behavior for humanoid characters in a "free" state.
 * Humanoids change direction periodically and move either left or right.
 */
void Humanoid::moveInFree()
{
    if (_timer.readTime() >= 0.4)
    {
        if (_flag)
            moveLeft();
        else
            moveRight();
        _flag = !_flag;
        _timer.start();
    }
}

/**
 * @brief Moves the humanoid character based on its current status.
 *
 * This method handles the movement of the humanoid character based on its current status.
 * The behavior differs for free, abducted, and falling characters.
 */
void Humanoid::Move()
{
    switch (getStatus())
    {
    case Status::FREE:
        moveInFree();
        break;
    case Status::ABDUCTED:
        moveUp();
        break;
    case Status::FALLING:
        moveDown();
        break;
    default:
        break;
    }
}