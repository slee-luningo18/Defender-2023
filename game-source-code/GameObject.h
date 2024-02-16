/**
 * @file GameObject.h
 * @brief Definition of the base class for game objects in the game world.
 *
 * The GameObject class serves as the base class for various game objects
 * that inhabit the game world. It provides essential attributes and methods
 * common to all game objects, such as position, state, direction, objective, and speed.
 * Derived classes should override the Move() method to define the behavior
 * specific to the game object type.
 */
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Utils.h"
#include <memory>

/**
 * @class GameObject
 * @brief Base class for game objects in the game world.
 */
class GameObject
{
public:
 /**
     * @brief Constructor for the GameObject class.
     *
     * @param x Initial X position of the game object.
     * @param y Initial Y position of the game object.
     */
    GameObject(double,double);


    /**
     * @brief Check if the game object is alive.
     * @return True if the game object is alive, false otherwise.
     */
    bool isAlive()const;

    /**
     * @brief Get the X position of the game object.
     * @return The X position of the game object.
     */
    double getXpos()const;

    /**
     * @brief Get the Y position of the game object.
     * @return The Y position of the game object.
     */
    double getYpos()const;

    /**
     * @brief Set the state of the game object.
     *
     * @param state The new state to set.
     */
    void setState(ObjectState state);


    /**
     * @brief Get the state of the game object.
     * @return The state of the game object.
     */
    ObjectState getState()const;

    /**
     * @brief Set the direction of the game object.
     *
     * @param direction The new direction to set.
     */
    void setDirection(Direction);

    /**
     * @brief Get the direction of the game object.
     * @return The direction of the game object.
     */
    Direction getDirection()const;

    /**
     * @brief Set the position of the game object.
     *
     * @param x The new X position to set.
     * @param y The new Y position to set.
     */
    void setPosition(double,double);

    /**
     * @brief Set the heading of the game object.
     *
     * @param heading The new heading to set.
     */
    void setHeading(Heading);

    /**
     * @brief Get the heading of the game object.
     * @return The heading of the game object.
     */
    Heading getHeading()const;

    /**
     * @brief Set the objective of the game object.
     *
     * @param objective The new objective to set.
     */
    void setObjective(Objective);


    /**
     * @brief Get the objective of the game object.
     * @return The objective of the game object.
     */
    Objective getObjective()const;
 /**
     * @brief Set the status of the game object.
     *
     * @param status The new status to set.
     */
    void setStatus(Status);

    /**
     * @brief Get the status of the game object.
     * @return The status of the game object.
     */
    Status getStatus()const;

    /**
     * @brief Move the game object. Must be overridden by derived classes.
     */
    virtual void Move();
protected:
    double _xPosition;
    double _yPosition;
    double _objectSpeed;
private:
    Direction _objectDirection;
    ObjectState _objectState;
    Heading _heading;
    Objective _objective;
    Status _status;
};
typedef std::shared_ptr<GameObject> GameObjectPtr;
#endif // GAMEOBJECT_H