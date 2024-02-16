/**
 * @file WriteText.h
 * @brief Header file for the WriteText class.
 */

#ifndef WRITETEXT_H
#define WRITETEXT_H

#include "States.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
using std::string;

/**
 * @class WriteText
 * @brief A class for rendering and displaying text using SFML.
 */
class WriteText
{
public:
    /**
     * @brief Constructor for the WriteText class.
     */
    WriteText();

    /**
     * @brief Set the font to be used for text rendering.
     * @param font The font to be set.
     */
    void setFont(Font&);

    /**
     * @brief Set the text color.
     * @param textColor The color of the text.
     */
    void setTextColor(Color);

    /**
     * @brief Display the text in the provided RenderWindow.
     * @param window The RenderWindow in which to display the text.
     */
    void displayText(RenderWindow&);

    /**
     * @brief Create text with the given content, character size, position, and style (default: Text::Regular).
     * @param text The text content.
     * @param textSize The character size of the text.
     * @param textPosition The position of the text.
     * @param style The style of the text (default: Text::Regular).
     */
    void createText(string, int, Vector2f, Text::Style style = Text::Regular);

    /**
     * @brief Get the internal Text object.
     * @return The Text object used for rendering.
     */
    Text getText() const;
private:
    Font  _font;    ///< The font used for text rendering.
    Color _color;   ///< The text color.
    Text  _text;    ///< The Text object used for rendering.
};

#endif // WRITETEXT_H