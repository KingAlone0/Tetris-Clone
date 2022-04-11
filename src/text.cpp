#include "text.hpp"
#include <iostream>

Text::Text()
{
    m_text = "nil";
    m_transformable = v2i(0);
}
// TODO: Need to make diifferent when it's i 
Text::Text(const std::string name): m_text(name)
{
    m_font.loadFromFile("../textures/font.png");
    m_pos = v2i(0.f);
    m_distance = 0;
    m_transformable = v2i(0);
    test_size = 0;
    for (size_t i = 0; i < m_text.size(); ++i) {
        if ((m_text[i] >= 65 && m_text[i] <= 90) | (m_text[i] >= 97 && m_text[i] <= 122)) {
           test_size += m_text[i] == 'I' && m_text[i] == 'i' ? 5 : 11; 
        }
    }
    setSprite();
}

void Text::setSprite()
{
    sf::Image font;
    sf::Image text;
    font.loadFromFile("../textures/font.png");
    // text.create(m_text.size() * 11, 200, sf::Color::Transparent);
    // HERE!!
    // Being Called twice??????
    text.create(test_size, 200, sf::Color::Transparent);
    bool special_char = false;
    int px = 0;
    m_transformable.x = m_text.size();
    for (size_t i = 0; i < m_text.size(); ++i)
    {
        if (m_text[i] >= 65 && m_text[i] <= 90)
        {
            int x, y;
            x = ((int)m_text[i] - 65);
            if (x >= 16) {
                x =(x - 16) * 11; 
                y = 13;
            } else {
                x *= 11;
                y = 0;
            }
            if (i == 0) {
                text.copy(font, 0, 0, sf::IntRect(x, y, 10, 12));
                px = m_text[i] == 'I' ? 6 : 11;
                m_transformable.y += m_text[i] == 'I' ? 5 : 11;
            } else if (special_char) 
            { 
                text.copy(font, px, 6, sf::IntRect(x, y, 10, 12)); 
                px += 11; 
                special_char = false;
                m_transformable.y += m_text[i] == 'I' ? 5 : 11;
            } else {
                text.copy(font, px, 0, sf::IntRect(x, y, 10, 12));
                m_transformable.y += m_text[i] == 'I' ? 5 : 11;
                px += 11;
            }
        } else if (m_text[i] >= 97 && m_text[i] <= 122) 
        {
            int x, y;
            x = ((int)m_text[i] - 97);
            if (x >= 16) {
                x = (x - 16) * 11; 
                y = 13;
            } else {
                x *= 11;
                y  = 0;
            }
            if (i == 0) {
                text.copy(font, 0, 0, sf::IntRect(x, y, 10, 12));
                px = m_text[i] == 'i' ? 6 : 11;
                m_transformable.y += m_text[i] == 'i' ? 5 : 11;
            } else {
                if (m_text[i] == 'i') {
                    text.copy(font, px, 0, sf::IntRect(x, y, 5, 12));
                    px += 5;
                    special_char = true;
                    m_transformable.y += m_text[i] == 'i' ? 5 : 11;
                } else if (special_char) {
                    text.copy(font, px, 0, sf::IntRect(x, y, 10, 12));
                    px += 11;
                    special_char = false;
                    m_transformable.y += m_text[i] == 'i' ? 5 : 11;
                } else {
                    text.copy(font, px, 0, sf::IntRect(x, y, 10, 12));
                    px += 11;
                    m_transformable.y += m_text[i] == 'i' ? 5 : 11;
                }
            }
        }
    }
    m_font.loadFromImage(text);
    spr.setTexture(m_font);
    spr.setPosition(V2f(m_pos));
}

V2 Text::getPosition() const
{
    return m_pos;
}

uint8_t Text::getDistance() const
{
    return m_distance;
}

V2 Text::getTSize() const
{
    return m_transformable;
}

void Text::setPosition(float x, float y)
{
    m_pos.x = x;
    m_pos.y = y;
    spr.setPosition(x, y);
}
void Text::setPosition(V2 pos)
{
    m_pos = pos;
    spr.setPosition(V2f(pos));
}

void Text::Update(RenderWindow *window)
{
    if (m_text == "nil") 
        return;
    window->draw(spr);
}

