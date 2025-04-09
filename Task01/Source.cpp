#include <SFML/Graphics.hpp>
#include "Flower.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "SFML works!");
  
    Flower flower(window);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        flower.draw();
        window.display();
    }
}