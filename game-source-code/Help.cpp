#include "Help.h"
#include <string>
#include <stdexcept>
#include <fstream>

using namespace std;

/**
 * @brief Constructor for the Help class.
 *
 * Initializes the Help state, loads necessary resources, and sets up text for display.
 *
 * @param Stack Reference to the StateStack for managing game states.
 */
Help::Help(StateStack& Stack) : State(Stack), _screenData(States::Help) {
    _helpText.setFont(_screenData.getFont(Fonts::TimeSplitter));
    _helpText.setTextColor(Color::Blue);
    setHelpTexts();
    paintBackground();
}

/**
 * @brief Event handler for the Help state.
 *
 * Handles user input events, such as closing the window or going back to the previous state.
 *
 * @param event The SFML event to handle.
 * @param window Reference to the RenderWindow.
 * @return True if the event was handled, false otherwise.
 */
bool Help::handleEvent(const sf::Event& event, RenderWindow& window) {
    if (event.type == sf::Event::Closed)
        window.close();
    if (event.type == Event::KeyPressed) {
        switch (event.key.code) {
            case Keyboard::Backspace:
                requestStackPop();
                return true;
            default:
                break;
        }
    }
    return false;
}

/**
 * @brief Set up the help text from external files.
 *
 * Reads the help text content and positions from files and creates Text objects for display.
 */
void Help::setHelpTexts() {
    auto line = string{""};
    auto x = 0, y = 0;
    auto charaterSize = 38;
    ifstream textReader("resources/HelpTexts.txt");
    if (!textReader)
        throw logic_error("HelpTexts.txt could not be opened");
    ifstream positionReader("resources/HelpTextsPositions.txt");
    if (!positionReader)
        throw logic_error("HelpTextsPositions.txt could not be opened");

    for (int i = 0; i < 9; i++) {
        getline(textReader, line);
        positionReader >> x >> y;
        if (i == 2) {
            _helpText.setTextColor(Color::White);
        }
        _helpText.createText(line, charaterSize, Vector2f(x, y), Text::Bold);
        _helpTexts.push_back(_helpText.getText());
    }
    textReader.close();
    positionReader.close();
}

/**
 * @brief Draw help texts on the screen.
 *
 * Iterates through the list of help texts and draws them on the provided RenderWindow.
 *
 * @param window Reference to the RenderWindow.
 */
void Help::drawHelpTexts(RenderWindow& window) {
    for (Text text : _helpTexts) {
        window.draw(text);
    }
}

/**
 * @brief Paint the background of the Help state.
 *
 * Loads and sets the background texture and color for the Help state.
 */
void Help::paintBackground() {
    _background.setTexture(_screenData.getTexture(Textures::HelpBackground));
    _background.setColor(Color(255, 255, 255, 255));
    _background.setPosition(0, 0);
}

/**
 * @brief Draw the Help state.
 *
 * Clears the RenderWindow, draws the background and help texts, and then displays the content.
 *
 * @param window Reference to the RenderWindow.
 */
void Help::draw(RenderWindow& window) {
    window.clear();
    window.draw(_background);
    drawHelpTexts(window);
    window.display();
}

/**
 * @brief Update the Help state.
 *
 * This function doesn't perform any state-specific updates, and it always returns false.
 *
 * @param dt Time elapsed since the last frame.
 * @return Always returns false.
 */
bool Help::update(Time dt) {
    return false;
}