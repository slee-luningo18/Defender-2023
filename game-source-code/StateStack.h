/**
 * @file StateStack.h
 * @brief Header file for the StateStack class.
 */

#ifndef STATESTACK_H
#define STATESTACK_H

#include <map>
#include <functional>
#include "States.h"

/**
 * @class StateStack
 * @brief A stack-based state management system for a game.
 */
class StateStack
{
public:
    /**
     * @enum Action
     * @brief Enumeration of possible actions to manipulate the state stack.
     */
    enum Action
    {
        Push, ///< Push a new state onto the stack.
        Pop,  ///< Pop the current state from the stack.
        Clear ///< Clear all states from the stack.
    };

public:
    /**
     * @brief Constructor for the StateStack class.
     */
    explicit StateStack();

    /**
     * @brief Register a state with a specific state ID.
     * @param stateID The ID of the state to register.
     */
    void registerState(States stateID);

    /**
     * @brief Update the states in the stack with the specified time.
     * @param dt The time elapsed since the last update.
     */
    void update(sf::Time dt);

    /**
     * @brief Draw the states in the stack in the provided RenderWindow.
     * @param window The RenderWindow in which to draw the states.
     */
    void draw(RenderWindow&);

    /**
     * @brief Handle an event for the states in the stack.
     * @param event The SFML event to be handled.
     * @param window The RenderWindow for handling the event.
     */
    void handleEvent(const sf::Event&, RenderWindow&);

    /**
     * @brief Push a new state onto the stack with the specified state ID.
     * @param stateID The ID of the state to push.
     */
    void pushState(States stateID);

    /**
     * @brief Pop the current state from the stack.
     */
    void popState();

    /**
     * @brief Clear all states from the stack.
     */
    void clearStates();

    /**
     * @brief Check if the state stack is empty.
     * @return True if the stack is empty, false otherwise.
     */
    bool isEmpty() const;

private:
    /**
     * @brief Create a state with the specified state ID.
     * @param stateID The ID of the state to create.
     * @return A smart pointer to the created state.
     */
    State::Ptr createState(States stateID);

    /**
     * @brief Apply pending changes to the state stack.
     */
    void applyPendingChanges();

private:
    /**
     * @struct PendingChange
     * @brief Structure representing a pending change in the state stack.
     */
    struct PendingChange
    {
        Action action;  ///< The action to perform (Push, Pop, or Clear).
        States stateID; ///< The ID of the state associated with the action.
    };

private:
    std::vector<State::Ptr> myStack; ///< A vector to store the states in the stack.
    std::vector<PendingChange> PendingList; ///< A vector to store pending changes.
    std::map<States, std::function<State::Ptr()>> Factories; ///< A map of state factories.
};

#endif