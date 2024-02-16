/**
 * @file Help.h
 * @brief Declaration of the Help class for the "Help" state in the game.
 *
 * This file contains the declaration of the Help class, which handles the "Help" state in the game.
 * The Help state displays helpful text and provides information to the player.
 */

#ifndef HELP_H
#define HELP_H

#include "States.h"
#include "WriteText.h"
#include "DataBase.h"
#include <vector>

/**
 * @brief Represents the "Help" state of the game.
 *
 * This class handles the "Help" state in the game. It displays helpful text and provides information to the player.
 */
class Help : public State
{
public:
    /**
     * @brief Constructs a Help state.
     *
     * @param stack Reference to the StateStack.
     */
    Help(StateStack&);

    /**
     * @brief Draws the contents of the Help state.
     *
     * @param window The RenderWindow to draw on.
     */
    virtual void draw(RenderWindow&);

    /**
     * @brief Updates the Help state.
     *
     * @param dt Time elapsed since the last update.
     * @return True if the state is updated successfully, false otherwise.
     */
    virtual bool update(Time dt);

    /**
     * @brief Handles events for the Help state.
     *
     * @param event The event to handle.
     * @param window The RenderWindow associated with the event.
     * @return True if the event is handled, false otherwise.
     */
    virtual bool handleEvent(const Event&, RenderWindow&);

private:
    /**
     * @brief Draws the help texts on the given RenderWindow.
     *
     * @param window The RenderWindow to draw the help texts on.
     */
    void drawHelpTexts(RenderWindow&);

    /**
     * @brief Paints the background of the Help state.
     */
    void paintBackground();

    /**
     * @brief Sets the help texts to be displayed.
     */
    void setHelpTexts();

    vector<Text> _helpTexts; /**< Vector of Text objects containing the help texts. */
    DataBase _screenData; /**< Database containing game data. */
    WriteText _helpText; /**< Helper class for managing text rendering. */
    Sprite _background; /**< Background sprite of the Help state. */
    Texture _texture; /**< Texture for the background. */
};

#endif // HELP_H
