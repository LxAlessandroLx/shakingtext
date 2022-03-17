#include "ShakingText.h"
#include <iostream>

ShakingText::ShakingText
(
    std::string text, sf::Font & font, unsigned int size, sf::Vector2f position, 
    int shakeIntensity, float speed, sf::Color fillColor, SPOT spot
)
    : m_position(position), m_shakeIntensity(shakeIntensity), m_speed(speed), m_spot(spot)
{
    m_text.reserve(text.length());

    for (int i = 0; i < (int)text.length(); ++i)
    {
        m_text.push_back(sf::Text());
        m_text[i].setFont(font);
        m_text[i].setCharacterSize(size);
        m_text[i].setFillColor(fillColor);
        m_text[i].setString(text[i]);
    }

    reset();
}

void ShakingText::setText(std::string text)
{
    // m_typedtext = text;
}

void ShakingText::setPosition(sf::Vector2f position)
{
    m_position = position;
    reset();
}

void ShakingText::reset()
{
    int currentPos = 0;

    switch (m_spot)
    {
        case LEFT:
        {
            for (int i = 0; i < (int)m_text.size(); ++i)
            {
                m_text[i].setPosition(m_position.x + currentPos, m_position.y);

                currentPos += m_text[i].getLocalBounds().width + m_text[i].getLetterSpacing()*4;
            } 
            break;
        }
        case RIGHT:
        {
            for (int i = m_text.size()-1; i >= 0; --i)
            {
                currentPos += m_text[i].getLocalBounds().width + m_text[i].getLetterSpacing()*4;

                m_text[i].setPosition(m_position.x - currentPos, m_position.y);
            }
            break;
        }
    }
}

void ShakingText::update()
{
    m_elapsedtime += m_counter.restart();

    if (m_elapsedtime >= sf::seconds(m_speed))
    {
        m_elapsedtime -= sf::seconds(m_speed);
        reset();
    }
    else
    {
        for (sf::Text & letter : m_text)
        {
            letter.move(
                rand() % (m_shakeIntensity*2 + 1) - m_shakeIntensity, 
                rand() % (m_shakeIntensity*2 + 1) - m_shakeIntensity
            );
        }
    }
}

void ShakingText::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    for (int i = 0; i < (int)m_text.size(); ++i)
        target.draw(m_text[i], states);
}
