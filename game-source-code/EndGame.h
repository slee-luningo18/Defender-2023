/**
 * @file EndGame.h
 * @brief Defines the EndGame state class for the game.
 */

/**
 * @class EndGame
 * @brief Represents the end game state.
 */
#ifndef ENDGAME_H
#define ENDGAME_H

#include "States.h"
#include "WriteText.h"
#include "FileHandler.h"
#include "DataBase.h"
#include <vector>

/**
 * @class EndGame
 * @brief Represents the end game state.
 */
class EndGame : public State
{
public:
    /**
     * @brief Constructor for the EndGame class.
     * @param Stack The state stack.
     */
    EndGame(StateStack&);

    /**
     * @brief Function to draw the EndGame state.
     * @param window The render window to draw on.
     */
    virtual void draw(RenderWindow&);

    /**
     * @brief Function to update the EndGame state.
     * @param dt The time elapsed since the last update.
     * @return True if the state is updated, false otherwise.
     */
    virtual bool update(Time dt);

    /**
     * @brief Function to handle events in the EndGame state.
     * @param event The event to handle.
     * @param window The render window.
     * @return True if the event is handled, false otherwise.
     */
    virtual bool handleEvent(const Event&, RenderWindow&);

private:
    /**
     * @brief Function to draw texts on the screen.
     * @param window The render window to draw on.
     */
    void drawScreenTexts(RenderWindow&);

    /**
     * @brief Function to set the background.
     */
    void paintBackground();

    /**
     * @brief Function to set text data on the screen.
     */
    void setScreenTexts();

    /**
     * @brief Function to retrieve game results.
     * @return A string representing the game results.
     */
    string gameResults() const;

    // Private member variables
    string _score;  // Variable to store the score.
    string _gameResults;  // Variable to store the game results.
    FileHandler _readOrWrite;  // File handler for reading/writing data.
    vector<Text> _screenTexts;  // Vector to store screen text elements.
    DataBase _endGameData;  // Data for the EndGame state.
    WriteText _resultText;  // Text for displaying results.
    WriteText _screenText;  // Text for the screen.
    Sprite _background;  // Background sprite.
    Texture _texture;  // Texture for the background.
};

#endif //ENDGAME_H