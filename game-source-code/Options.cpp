/**
 * @file Options.cpp
 * @brief Contains the implementation of the Options class, representing the game's options menu state.
 */

#include "Options.h"
#include <string>
#include <stdexcept>
#include <fstream>

/**
 * @brief Constructs the Options state.
 * @param Stack Reference to the state stack for managing game states.
 */
Options::Options(StateStack& Stack) : State(Stack), _screenData(States::Options)
{
    _instruction.setTextColor(Color::White);
    _instruction.setFont(_screenData.getFont(Fonts::TimeSplitter));
    _changes.setFont(_screenData.getFont(Fonts::TimeSplitter));
    _optionsIndex = 0;
    _showChanges = false;
    setInstructions();
    paintBackground();
}

/**
 * @brief Handles events in the Options state.
 * @param event The event to handle.
 * @param window The RenderWindow where the event occurred.
 * @return True if the event was handled; otherwise, false.
 */
bool Options::handleEvent(const sf::Event& event, RenderWindow& window)
{
    if (event.type == sf::Event::Closed)
        window.close();

    if (event.type == Event::KeyPressed)
    {
        _showChanges = false;
        switch (event.key.code)
        {
        case Keyboard::Up:
            if (_optionsIndex > 0)
                _optionsIndex--;
            else
                _optionsIndex = static_cast<int>(_instructions.size()) - 1;
            break;
        case Keyboard::Down:
            if (_optionsIndex < static_cast<int>(_instructions.size()) - 1)
                _optionsIndex++;
            else
                _optionsIndex = 0;
            break;
        case Keyboard::Escape:
            window.close();
            break;
        case Keyboard::Enter:
            optionSelection();
            break;
        case Keyboard::Backspace:
            requestStackPop();
            return true;
            break;
        default:;
        }
    }
    return false;
}

/**
 * @brief Handles the selected option and performs the corresponding action.
 */
void Options::optionSelection()
{
    switch (_optionsIndex)
    {
    case View:
        viewScore();
        break;
    case Reset:
        resetScore();
        break;
    default:;
    }
}

/**
 * @brief Displays the current high score.
 */
void Options::viewScore()
{
    auto highScore = 0;
    ifstream scoreReader("resources/HighScore.txt");
    if (!scoreReader)
        throw logic_error("HelpTextsPositions.txt could not be opened");
    scoreReader >> highScore;
    string highScoreStr = to_string(highScore);
    _changes.createText("Current high score is " + highScoreStr, 50, Vector2f(250, 400), Text::Bold);
    _showChanges = true;
    scoreReader.close();
}

/**
 * @brief Resets the high score to zero.
 */
void Options::resetScore()
{
    auto newScore = 0;
    ofstream scoreWriter("resources/HighScore.txt");
    scoreWriter << newScore;
    _changes.createText("High score has been reset", 50, Vector2f(250, 400), Text::Bold);
    _showChanges = true;
    scoreWriter.close();
}

/**
 * @brief Paints the background for the Options state.
 */
void Options::paintBackground()
{
    _background.setTexture(_screenData.getTexture(Textures::OptionsBackground));
    _background.setColor(Color(255, 255, 255, 255));
    _background.setPosition(0, 0);
}

/**
 * @brief Sets the instructions for the available options.
 */
void Options::setInstructions()
{
    _instruction.createText("View high score", 50, Vector2f(330, 150), Text::Bold);
    _instructions.push_back(_instruction.getText());
    _instruction.createText("Reset high score", 50, Vector2f(335, 250), Text::Bold);
    _instructions.push_back(_instruction.getText());
}

void Options::drawInstructions(RenderWindow& window)
{
    for(Text text: _instructions)
    {
        window.draw(text);
    }
}

/**
 * @brief Draws the Options state on the given window.
 * @param window The RenderWindow to draw on.
 */
void Options::draw(RenderWindow& window)
{
    window.clear();
    window.draw(_background);
    drawInstructions(window);
    if (_showChanges == true)
        _changes.displayText(window);

    window.display();
}

/**
 * @brief Updates the Options state.
 * @param dt The time elapsed since the last update.
 * @return False, as this state does not modify the stack.
 */
bool Options::update(Time dt)
{
    for (Text& text : _instructions)
    {
        text.setFillColor(Color::White);
    }
    _instructions[_optionsIndex].setFillColor(Color::Green);

    return false;
}