#include "Exit.h"

/**
 * @brief Constructs the Exit state.
 * @param Stack The state stack.
 */
Exit::Exit(StateStack& Stack) : State(Stack), _screenData(States::Exit) {
    _exitOptions.setFont(_screenData.getFont(Fonts::TimeSplitter));
    _exitOptions.setTextColor(Color::Cyan);
    _heading.setFont(_screenData.getFont(Fonts::FireStorm));
    _heading.setTextColor(Color::Red);
    _heading.createText("Are you sure you want to quit ?", 40, Vector2f(85, 365), Text::Bold);
    _optionsIndex = 1;
    setExitOptions();
}

/**
 * @brief Handles events in the Exit state.
 * @param event The event to handle.
 * @param window The game window.
 * @return True if the event is handled, otherwise false.
 */
bool Exit::handleEvent(const sf::Event& event, RenderWindow& window) {
    if (event.type == sf::Event::Closed)
        window.close();
    if (event.type == Event::KeyPressed) {
        switch (event.key.code) {
            case Keyboard::Left:
                if (_optionsIndex > 0)
                    _optionsIndex--;
                else
                    _optionsIndex = static_cast<int>(_options.size()) - 1;
                break;
            case Keyboard::Right:
                if (_optionsIndex < static_cast<int>(_options.size()) - 1)
                    _optionsIndex++;
                else
                    _optionsIndex = 0;
                break;
            case Keyboard::Enter:
                if (_optionsIndex == Yes)
                    window.close();
                else {
                    requestStackPop();
                    requestStackPush(States::Menu);
                }
                break;
            default:;
        }
    }
    return true;
}

/**
 * @brief Sets the exit options.
 */
void Exit::setExitOptions() {
    _exitOptions.createText("Yes", 38, Vector2f(380, 430));
    _options.push_back(_exitOptions.getText());
    _exitOptions.createText("No", 38, Vector2f(480, 430));
    _options.push_back(_exitOptions.getText());
}

/**
 * @brief Draws the exit options on the window.
 * @param window The game window.
 */
void Exit::drawExitOptions(RenderWindow& window) {
    for (Text text : _options) {
        window.draw(text);
    }
}

/**
 * @brief Draws the Exit state.
 * @param window The game window.
 */
void Exit::draw(RenderWindow& window) {
    RectangleShape rectangle;
    rectangle.setFillColor(Color::Black);
    rectangle.setOutlineColor(Color::Red);
    rectangle.setOutlineThickness(3.0f);
    rectangle.setSize(Vector2f(740, 150));
    rectangle.setPosition(Vector2f(83, 358));
    window.draw(rectangle);
    _heading.displayText(window);
    drawExitOptions(window);
    window.display();
}

/**
 * @brief Updates the Exit state.
 * @param dt The elapsed time.
 * @return Always returns true.
 */
bool Exit::update(Time dt) {
    for (Text& text : _options) {
        text.setFillColor(Color(73, 32, 0));
    }
    _options[_optionsIndex].setFillColor(Color(191, 112, 6));
    return true;
}