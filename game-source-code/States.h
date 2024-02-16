/**
 * @file States.h
 * @brief Header file for the State class.
 */

#ifndef STATES_H
#define STATES_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "GameStates.h"

using namespace sf;
using namespace std;
/**
 * @class State
 * @brief An abstract base class representing a game state.
 */
class StateStack;
class State
{
public:
    /**
     * @typedef Ptr
     * @brief Typedef for a smart pointer to a State object.
     */
    typedef std::unique_ptr<State> Ptr;

public:
    /**
     * @brief Constructor for the State class.
     * @param Stack The StateStack to which the state belongs.
     */
    explicit State(StateStack& Stack);

    /**
     * @brief Destructor for the State class.
     */
    virtual ~State();

    /**
     * @brief Draw the state in the provided RenderWindow.
     * @param window The RenderWindow in which to draw the state.
     */
    virtual void draw(RenderWindow&) = 0;

    /**
     * @brief Update the state with the specified time.
     * @param dt The time elapsed since the last update.
     * @return True if the update is successful, false otherwise.
     */
    virtual bool update(sf::Time dt) = 0;

    /**
     * @brief Handle an event for the state.
     * @param event The SFML event to be handled.
     * @param window The RenderWindow for handling the event.
     * @return True if the event is successfully handled, false otherwise.
     */
    virtual bool handleEvent(const sf::Event&, RenderWindow&) = 0;

protected:
    /**
     * @brief Request pushing a new state onto the StateStack with a specified state ID.
     * @param stateID The ID of the state to push.
     */
    void requestStackPush(States stateID);

    /**
     * @brief Request popping the current state from the StateStack.
     */
    void requestStackPop();

    /**
     * @brief Request clearing the StateStack of all states.
     */
    void requestStateClear();

private:
    StateStack* myStack; ///< A pointer to the StateStack to which the state belongs.
};

#endif