#include <iostream>
#include <SFML/Graphics.hpp>
#include "ColorSM.h"

int main()
{
    std::cout << "hello world" << std::endl;
    
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    ColorSM color_state(0.3f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        color_state.Run();
        shape.setFillColor(color_state.GetColor());

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}