/**
 * @file Menu.h
 * @brief Defines the Menu class for handling the main menu state of the game.
 */

#ifndef MENU_H
#define MENU_H
#include "States.h"
#include "WriteText.h"
#include "DataBase.h"
#include <vector>

/**
 * @class Menu
 * @brief Represents the main menu state of the game.
 *
 * This class extends the State class and provides functionality for
 * displaying and handling the main menu options of the game.
 */
class Menu : public State
{
public:
    /**
     * @enum MenuOptions
     * @brief Represents the available menu options.
     */
    enum MenuOptions
    {
        Play, Options, Help, Quit
    };

    /**
     * @brief Constructor for the Menu class.
     * @param stack The StateStack managing the game's states.
     */
    Menu(StateStack&);

    /**
     * @brief Renders the main menu screen.
     * @param window The RenderWindow to render the menu on.
     */
    virtual void draw(RenderWindow&);

    /**
     * @brief Updates the main menu state based on the elapsed time.
     * @param dt The elapsed time since the last update.
     * @return True if the state needs to be updated further, false if it's ready to transition.
     */
    virtual bool update(Time dt);

    /**
     * @brief Handles events in the main menu state.
     * @param event The event to handle.
     * @param window The RenderWindow to handle the event on.
     * @return True if the event was handled, false otherwise.
     */
    virtual bool handleEvent(const Event&, RenderWindow&);

private:
    /**
     * @brief Paints the background of the main menu.
     */
    void paintBackground();

    /**
     * @brief Updates the appearance of menu options.
     */
    void updateOptionsText();

    /**
     * @brief Draws the main menu options.
     * @param window The RenderWindow to draw the options on.
     */
    void drawMenuOptions(RenderWindow&);

    /**
     * @brief Sets up the main menu options.
     */
    void setMenuOptions();
    void optionSelection();
    int _optionsIndex;          /**< The currently selected menu option index. */
    vector<Text> _options;      /**< The menu options text objects. */
    DataBase _screenData;       /**< The data for the menu screen. */
    WriteText _menuOptions;     /**< Utility for creating menu option text. */
    Sprite _background;        /**< The menu background image. */
    Sprite _pointer;           /**< The selection pointer image. */
    Texture _texture;          /**< Texture for the menu background. */
    Texture _pointerTexture;   /**< Texture for the selection pointer. */
};

#endif // MENU_H
