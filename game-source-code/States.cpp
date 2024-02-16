#include "States.h"
#include "StateStack.h"

/**
 * @brief Constructor for the State class.
 * @param Stack The StateStack to which the state belongs.
 */
State::State(StateStack& Stack): myStack{&Stack} {}

/**
 * @brief Destructor for the State class.
 */
State::~State() {}

/**
 * @brief Request popping the current state from the StateStack.
 */
void State::requestStackPop()
{
    myStack->popState();
}

/**
 * @brief Request pushing a new state onto the StateStack with a specified state ID.
 * @param StateId The ID of the state to push.
 */
void State::requestStackPush(States StateId)
{
    myStack->pushState(StateId);
}

/**
 * @brief Request clearing the StateStack of all states.
 */
void State::requestStateClear()
{
    myStack->clearStates();
}