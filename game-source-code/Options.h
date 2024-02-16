/**
 * @file Options.h
 * @brief Header file for the Options class.
 */

#ifndef OPTIONS_H
#define OPTIONS_H

#include "States.h"
#include "WriteText.h"
#include "DataBase.h"
#include <vector>

/**
 * @class Options
 * @brief A class representing the Options menu in the game.
 */
class Options : public State
{
public:
    /**
     * @brief Enumeration for available options in the Options menu.
     */
    enum Option
    {
        View, Reset
    };

public:
    /**
     * @brief Constructor for the Options class.
     * @param stack A reference to the StateStack.
     */
    Options(StateStack&);

    /**
     * @brief Function to draw the Options menu.
     * @param window The RenderWindow to draw on.
     */
    virtual void draw(RenderWindow&);

    /**
     * @brief Function to update the Options menu.
     * @param dt The elapsed time.
     * @return True if the menu is successfully updated, false otherwise.
     */
    virtual bool update(Time dt);

    /**
     * @brief Function to handle events in the Options menu.
     * @param event The event to handle.
     * @param window The RenderWindow.
     * @return True if the event is successfully handled, false otherwise.
     */
    virtual bool handleEvent(const Event&, RenderWindow&);

private:
    /**
     * @brief Function to draw instructions on the screen.
     * @param window The RenderWindow to draw on.
     */
    void drawInstructions(RenderWindow&);

    /**
     * @brief Function to set the instructions.
     */
    void setInstructions();

    /**
     * @brief Function to paint the background.
     */
    void paintBackground();

    /**
     * @brief Function to handle option selection.
     */
    void optionSelection();

    /**
     * @brief Function to view the score.
     */
    void viewScore();

    /**
     * @brief Function to reset the score.
     */
    void resetScore();

    int _optionsIndex; ///< The current selected option index.
    vector<Text> _instructions; ///< The instruction texts.
    DataBase _screenData; ///< Data related to the Options screen.
    WriteText _instruction; ///< The instruction text.
    WriteText _changes; ///< The change indicator text.
    Sprite _background; ///< The background sprite.
    Texture _texture; ///< The texture for the background.
    bool _showChanges; ///< A flag to indicate if changes are shown.
};

#endif // OPTIONS_H
