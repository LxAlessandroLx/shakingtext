## Example
An example of how to use it
```c++
#include "ShakingText.h"

int main()
{
    const unsigned int screenWidth = 800;
    const unsigned int screenHeight = 600;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "ShakingText");
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("path/to/font.ttf");

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
```
- "path/to/font.ttf" is your font path
- "This is an example text" is the text to display
- 32 is the fontsize
- {100, 100} is the text position
- .05f (1/20 aka 20 per second) is the time for text repositioning
- sf::Color::White is the text color
- LEFT is the text alignment
