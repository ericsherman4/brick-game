#pragma once

#include <SFML/Graphics/Color.hpp>
#include <iostream>

class RainbowColorAnim
{
public:
    RainbowColorAnim(float anim_speed)
        : m_ANIM_SPEED(anim_speed)
        , m_red (255.f)
        , m_green (0.f)
        , m_blue(0.f)
    {
    }

    void Run()
    {
        static float t = 0.f;

        t += m_ANIM_SPEED;
        std::cout << t << ": " << m_green << std::endl;

        if (t > FULL_CYCLE_TIME){ t = 0.f; }

        // implement piecewise functions from the fastLED "rainbow" hue chart.

        m_red =
            (t < 85.f) * (-t + 255.f) +
            (85.f <= t && t < 170.f) * (170.f) +
            (170.f <= t && t < 255.f) * (-2.f * t + 510.f) +
            (255.f <= t && t < 425.f) * (0.f) +
            (425.f <= t && t < 680.f) * (t - 425.f );

        m_green =
            (t < 255.f) * (t) +
            (255.f <= t && t < 340.f) * (-t + 510) +
            (340.f <= t && t < 425.f) * (-2.f * t + 850.f) +
            (425.f <= t && t < 680.f) * (0.f);

        m_blue =
            (t < 255.f) * (0.f) +
            (255.f <= t && t < 340.f) * (t - 255.f) +
            (340.f <= t && t < 425.f) * (2.f*t - 595.0f) +
            (425.f <= t && t < 680.f) * (-t + 680.f);
    }

    sf::Color GetColor()
    {
        return { (uint8_t)m_red, (uint8_t)m_green, (uint8_t)m_blue };
    }

private:
    static constexpr float FULL_CYCLE_TIME = 255 * 2 + 255 * 2 / 3;
    const float m_ANIM_SPEED;
    float m_red;
    float m_green;
    float m_blue;
};

