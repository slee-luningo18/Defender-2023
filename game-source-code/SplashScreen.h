/**
 * @file SplashScreen.h
 * @brief Header file for the SplashScreen class.
 */

#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "States.h"
#include "DataBase.h"
#include "WriteText.h"
#include <vector>

/**
 * @class SplashScreen
 * @brief A class representing the splash screen state of the game.
 */
class SplashScreen : public State
{
public:
    /**
     * @brief Constructor for the SplashScreen class.
     * @param Stack The StateStack to which the splash screen belongs.
     */
    SplashScreen(StateStack&);

    /**
     * @brief Draw the splash screen in the provided RenderWindow.
     * @param window The RenderWindow in which to draw the splash screen.
     */
    virtual void draw(RenderWindow&);

    /**
     * @brief Update the splash screen with the specified time.
     * @param dt The time elapsed since the last update.
     * @return True if the update is successful, false otherwise.
     */
    virtual bool update(Time dt);

    /**
     * @brief Handle an event for the splash screen.
     * @param event The SFML event to be handled.
     * @param window The RenderWindow for handling the event.
     * @return True if the event is successfully handled, false otherwise.
     */
    virtual bool handleEvent(const Event&, RenderWindow&);

private:
    /**
     * @brief Set the text to be displayed on the splash screen.
     */
    void setScreenText();

    /**
     * @brief Draw the text on the splash screen.
     * @param window The RenderWindow in which to draw the text.
     */
    void drawScreenText(RenderWindow&);

    /**
     * @brief Paint the background of the splash screen.
     */
    void paintBackground();

    vector<Text> _screenTexts; ///< A vector of text objects to be displayed on the splash screen.
    DataBase _screenData; ///< The data source for the splash screen.
    WriteText _screenText; ///< The text display helper.
    Sprite _background; ///< The background sprite.
    Texture _texture; ///< The texture for the background.
};

#endif // SPLASHSCREEN_H
