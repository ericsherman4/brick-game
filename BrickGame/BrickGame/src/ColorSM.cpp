#include "ColorSM.h"

ColorSM::ColorSM(float color_speed)
    : m_color_speed(color_speed)
    , m_red(0.f)
    , m_green(255.f)
    , m_blue(255.f)
    , m_curr_state(State::FALLING_G)
    , m_next_state(State::FALLING_G)
{
}

void ColorSM::Run()
{
    // https://stackoverflow.com/questions/5162458/fade-through-more-more-natural-rainbow-spectrum-in-hsv-hsb
    switch (m_curr_state)
    {
        case State::RISING_G:
            m_green += m_color_speed;
            if (m_green >= 255.f)
            {
                m_green = 255.f;
                m_next_state = State::FALLING_R;
            }
            break;
        case State::FALLING_R:
            m_red -= m_color_speed;
            if (m_red <= 0.f)
            {
                m_red = 0.f;
                m_next_state = State::RISING_B;
            }
            break;
        case State::RISING_B:
            m_blue += m_color_speed;
            if (m_blue >= 255.f)
            {
                m_blue = 255.f;
                m_next_state = State::FALLING_G;
            }
            break;
        case State::FALLING_G:
            m_green -= m_color_speed;
            if (m_green <= 0.f)
            {
                m_green = 0.f;
                m_next_state = State::RISING_R;
            }
            break;
        case State::RISING_R:
            m_red += m_color_speed;
            if (m_red >= 255.f)
            {
                m_red = 255.f;
                m_next_state = State::FALLING_B;
            }
            break;
        case State::FALLING_B:
            m_blue -= m_color_speed;
            if (m_blue <= 0.f)
            {
                m_blue = 0.f;
                m_next_state = State::RISING_G;
            }
            break;
    }

    m_curr_state = m_next_state;
}

sf::Color ColorSM::GetColor()
{
    return sf::Color(
        (float)m_red,
        (float)m_green,
        (float)m_blue
    );
}
