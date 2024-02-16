#include "StateStack.h"
#include "SplashScreen.h"
#include "Menu.h"
#include "Options.h"
#include "Help.h"
#include "Game.h"
#include "Exit.h"
#include "EndGame.h"
#include <cassert>
#include <iostream>

/**
 * @brief Default constructor for the StateStack class.
 */
StateStack::StateStack() {}

/**
 * @brief Register a state with a specified state ID.
 * @param stateID The ID of the state to register.
 */
void StateStack::registerState(States stateID)
{
    switch(stateID)
    {
    case States::Menu:
        Factories[stateID] = [this] ()
        {
            return State::Ptr(new Menu(*this));
        };
        break;
    case States::Options:
        Factories[stateID] = [this] ()
        {
            return State::Ptr(new Options(*this));
        };
        break;
    case States::Help:
        Factories[stateID] = [this] ()
        {
            return State::Ptr(new Help(*this));
        };
        break;
    case States::Game:
        Factories[stateID] = [this] ()
        {
            return State::Ptr(new Game(*this));
        };
        break;
    case States::Exit:
        Factories[stateID] = [this] ()
        {
            return State::Ptr(new Exit(*this));
        };
        break;
    case States::SplashScreen:
        Factories[stateID] = [this] ()
        {
            return State::Ptr(new SplashScreen(*this));
        };
        break;
    case States::EndGame:
        Factories[stateID] = [this] ()
        {
            return State::Ptr(new EndGame(*this));
        };
        break;
    default:
        cerr << "Invalid game state" << endl;
    }
}

/**
 * @brief Create a state with the specified state ID.
 * @param stateID The ID of the state to create.
 * @return A smart pointer to the created state.
 */
State::Ptr StateStack::createState(States stateID)
{
    auto found = Factories.find(stateID);
    assert(found != Factories.end());
    return found->second();
}

/**
 * @brief Push a new state onto the stack with the specified state ID.
 * @param StateId The ID of the state to push.
 */
void StateStack::pushState(States StateId)
{
    PendingChange temp;
    temp.action = Action::Push;
    temp.stateID = StateId;
    PendingList.push_back(temp);
    if(isEmpty())
    {
        applyPendingChanges();
    }
}

/**
 * @brief Pop the current state from the stack.
 */
void StateStack::popState()
{
    PendingChange temp;
    temp.action = Action::Pop;
    PendingList.push_back(temp);
}

/**
 * @brief Clear all states from the stack.
 */
void StateStack::clearStates()
{
    PendingChange temp;
    temp.action = Action::Clear;
    PendingList.push_back(temp);
}

/**
 * @brief Apply pending changes to the state stack.
 */
void StateStack::applyPendingChanges()
{
    for(PendingChange change: PendingList)
    {
        switch (change.action)
        {
        case Push:
            myStack.push_back(createState(change.stateID));
            break;
        case Pop:
            myStack.pop_back();
            break;
        case Clear:
            myStack.clear();
            break;
        }
    }
    PendingList.clear();
}

/**
 * @brief Handle an event for the states in the stack.
 * @param event The SFML event to be handled.
 * @param window The RenderWindow for handling the event.
 */
void StateStack::handleEvent(const sf::Event& event, RenderWindow& window)
{
    for (auto itr = myStack.rbegin(); itr != myStack.rend(); ++itr)
    {
        if (!(*itr)->handleEvent(event,window))
            return;
    }
    applyPendingChanges();
}

/**
 * @brief Update the states in the stack with the specified time.
 * @param dt The time elapsed since the last update.
 */
void StateStack::update(Time dt)
{
    for (auto itr = myStack.rbegin(); itr != myStack.rend(); ++itr)
    {
        if (!(*itr)->update(dt))
            return;
    }
    applyPendingChanges();
}

/**
 * @brief Check if the state stack is empty.
 * @return True if the stack is empty, false otherwise.
 */
bool StateStack::isEmpty() const
{
    return myStack.empty();
}

/**
 * @brief Draw the states in the stack in the provided RenderWindow.
 * @param window The RenderWindow in which to draw the states.
 */
void StateStack::draw(RenderWindow& window)
{
    if(!isEmpty())
    {
        auto iter = myStack.rbegin();
        (*iter)->draw(window);
    }
}