#include "WriteText.h"

/**
 * @brief Constructor for the WriteText class.
 */
WriteText::WriteText()
{
    _color = Color::White;
}

/**
 * @brief Set the font to be used for text rendering.
 * @param font The font to be set.
 */
void WriteText::setFont(Font& font)
{
    _font = font;
}

/**
 * @brief Set the text color.
 * @param newColor The color of the text.
 */
void WriteText::setTextColor(Color newColor)
{
    _color = newColor;
}

/**
 * @brief Create text with the given content, character size, position, and style.
 * @param text The text content.
 * @param textSize The character size of the text.
 * @param textPosition The position of the text.
 * @param style The style of the text.
 */
void WriteText::createText(string text, int textSize, Vector2f textPosition, Text::Style style)
{
    Text newText(text, _font, textSize);
    newText.setStyle(style);
    newText.setPosition(textPosition);
    newText.setFillColor(_color);
    _text = newText;
}

/**
 * @brief Display the text in the provided RenderWindow.
 * @param window The RenderWindow in which to display the text.
 */
void WriteText::displayText(RenderWindow& window)
{
    window.draw(_text);
}

/**
 * @brief Get the internal Text object.
 * @return The Text object used for rendering.
 */
Text WriteText::getText()const
{
    return _text;
}
