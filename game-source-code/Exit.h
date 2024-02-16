/**
 * @file Exit.h
 * @brief Defines the Exit state for handling exit confirmation.
 */
#ifndef EXIT_H
#define EXIT_H

#include "States.h"
#include "WriteText.h"
#include "DataBase.h"
#include <vector>

/**
 * @class Exit
 * @brief Represents the exit confirmation screen.
 */
class Exit : public State
{
public:
    /**
     * @brief Enumeration for exit options.
     */
    enum ExitOptions
    {
        Yes, /**< Option to confirm exit. */
        No   /**< Option to cancel exit. */
    };

public:
    /**
     * @brief Constructs the Exit state.
     *
     * @param Stack The state stack.
     */
    Exit(StateStack& Stack);

    /**
     * @brief Draws the Exit state.
     *
     * @param window The rendering window.
     */
    virtual void draw(RenderWindow&);

    /**
     * @brief Updates the Exit state.
     *
     * @param dt The time since the last update.
     * @return True if the state needs to be updated, false otherwise.
     */
    virtual bool update(Time dt);

    /**
     * @brief Handles events for the Exit state.
     *
     * @param event The event to handle.
     * @param window The rendering window.
     * @return True if the event was handled, false otherwise.
     */
    virtual bool handleEvent(const Event&, RenderWindow&);

private:
    /**
     * @brief Updates the text for exit options.
     */
    void updateOptionsText();

    /**
     * @brief Draws the exit options on the screen.
     *
     * @param window The rendering window.
     */
    void drawExitOptions(RenderWindow&);

    /**
     * @brief Sets the available exit options.
     */
    void setExitOptions();

    int _optionsIndex;          ///< Index of the selected exit option.
    vector<Text> _options;      ///< List of exit options.
    DataBase _screenData;       ///< Database for screen data.
    WriteText _heading;         ///< Text for the heading.
    WriteText _exitOptions;     ///< Text for the exit options.
};
#endif // EXIT_H
