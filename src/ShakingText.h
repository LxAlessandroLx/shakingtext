#ifndef TYPEWRITER_H
#define TYPEWRITER_H

#include <SFML/Graphics.hpp>
#include <vector>

enum SPOT { LEFT, RIGHT };

class ShakingText : public sf::Drawable
{
    private:
        std::vector<sf::Text> m_text;
        sf::Vector2f m_position;

        sf::Clock m_counter;
        sf::Time m_elapsedtime;

        int m_shakeIntensity;
        float m_speed;

        SPOT m_spot;

        void reset();
        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

    public:
        ShakingText(
            std::string text, sf::Font & font, unsigned int size = 18U, 
            sf::Vector2f position = sf::Vector2f(0,0), int shakeIntesity = 2,
            float speed = 1, sf::Color fillColor = sf::Color::Black, SPOT spot = LEFT
        );

        void setText(std::string text);
        void setPosition(sf::Vector2f position);
        void setSpeed(float speed) { m_speed = speed; }
        void setSpot(SPOT spot) { m_spot = spot; }

        void update();
};

#endif
