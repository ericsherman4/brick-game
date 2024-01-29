#include <SFML/Graphics.hpp>
#include "ColorSM.h"
#include "RainbowColorAnim.h"
#include <vector>


int main()
{
    sf::RenderWindow window(sf::VideoMode(2560, 1440), "SFML works!");

    // define rect params
    const int RECT_COUNT = 680;
    const float RECT_WIDTH = 2.f;
    const float RECT_HEIGHT = 500.f;

    sf::CircleShape circle(20);
    circle.setFillColor({ 255,255,0 });

    // set up color SM
    // 6*255 is the total number of increments needed for the SM if the speed is one. 
    // We have RECT_COUNT rectangles that are used to represent this, so we divide that to get the interval
    // we also multiple by 2 cause we are sweeping through the colors twice
    ColorSM color_state( 6.f * 255.f / (float)RECT_COUNT);
    RainbowColorAnim new_color(680.f / (float)RECT_COUNT);
    
    // Set up rectangles
    std::vector<sf::RectangleShape> color_strip;
    std::vector<sf::RectangleShape> color_strip_2;
    color_strip.reserve(RECT_COUNT);
    color_strip_2.reserve(RECT_COUNT);

    // build the strip 1
    for (int i =0; i < RECT_COUNT; i++){
    
        color_state.Run();

        sf::RectangleShape temp({ RECT_WIDTH,RECT_HEIGHT}) ;
        temp.setFillColor(color_state.GetColor());
        temp.setPosition(RECT_WIDTH * i + 100, 100);
        
        color_strip.push_back(temp);
    }

    // build the strip 2
    for (int i = 0; i < RECT_COUNT; i++) {

        new_color.Run();

        sf::RectangleShape temp({ RECT_WIDTH,RECT_HEIGHT });
        temp.setFillColor(new_color.GetColor());
        temp.setPosition(RECT_WIDTH * i + 100, 600);

        color_strip_2.push_back(temp);
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        for (auto rect : color_strip)
        {
            window.draw(rect);
        }

        for (auto rect : color_strip_2)
        {
            window.draw(rect);
        }

        window.draw(circle);

        window.display();
    }

    return 0;
}