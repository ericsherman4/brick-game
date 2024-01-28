#pragma once
#include <SFML/Graphics.hpp>

class ColorSM
{
public:
    ColorSM(float color_speed = 1.f);

    void Run();
    sf::Color GetColor();

private: 
    enum class State
    {
        RISING_G,
        FALLING_R,
        RISING_B,
        FALLING_G,
        RISING_R,
        FALLING_B
    };

    State m_curr_state;
    State m_next_state;
    float m_color_speed;

public:
    float m_red;
    float m_green;
    float m_blue;
};

