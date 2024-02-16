/**
 * @file Utils.h
 * @brief This file defines common enumerations and types used throughout the application.
 *
 * This header file provides a set of enumerations and types that are commonly used in various parts
 * of the application to represent directions, headings, object states, objectives, statuses, and buttons.
 * These definitions help maintain consistency and improve code readability.
 */
#ifndef UTILS_H
#define UTILS_H

#include <vector>

using std::vector;

/**
 * @enum Direction
 * @brief Enumeration of directions.
 */
typedef enum
{
    RIGHT,      ///< Right direction
    RIGHTDOWN,  ///< Right-down direction
    DOWN,       ///< Down direction
    LEFTUP,     ///< Left-up direction
    LEFT,       ///< Left direction
    LEFTDOWN,   ///< Left-down direction
    UP,         ///< Up direction
    RIGHTUP,    ///< Right-up direction
    NONE        ///< No specific direction
} Direction;

/**
 * @enum Heading
 * @brief Enumeration of headings.
 */
typedef enum
{
    LEFTHEADING,     ///< Left heading
    RIGHTHEADIND     ///< Right heading
} Heading;

/**
 * @enum ObjectState
 * @brief Enumeration of object states.
 */
typedef enum
{
    ALIVE,   ///< Object is alive
    DEAD,    ///< Object is dead
    FAIL
} ObjectState;

/**
 * @enum Objective
 * @brief Enumeration of objectives.
 */
typedef enum
{
    ATTACK,       ///< Attack objective
    ABDUCT,       ///< Abduct objective
    ESCAPE,       ///< Escape objective
    NOOBJECTIVE   ///< No specific objective
} Objective;

/**
 * @enum Status
 * @brief Enumeration of statuses.
 */
typedef enum
{
    FREE,     ///< Object is free
    FALLING,  ///< Object is falling
    ABDUCTED, ///< Object is abducted
    RESCUED,  ///< Object is rescued
    NOSTATUS  ///< No specific status
} Status;

/**
 * @enum Button
 * @brief Enumeration of buttons.
 */
enum class Button
{
    UP,    ///< Up button
    DOWN,  ///< Down button
    LEFT,  ///< Left button
    RIGHT, ///< Right button
    SPACE, ///< Space button
    NONE   ///< No specific button
};

#endif