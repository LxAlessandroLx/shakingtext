#include "ShakingText.h"

int main()
{
    const unsigned int screenWidth = 800;
    const unsigned int screenHeight = 600;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "ShakingText");
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("res/font.ttf");

    ShakingText text("This is an example text", font, 32, {100,100}, 2, .05f, sf::Color::White, LEFT);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        text.update();

        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
    }
}
