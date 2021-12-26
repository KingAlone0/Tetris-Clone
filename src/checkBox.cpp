#include "checkBox.hpp"

CheckBox::CheckBox(float x, float y)
{
    pos.x = x;
    pos.y = y;
    setBox();
    pressedTime.restart();
}

void CheckBox::setBox()
{
    box.setSize(sf::Vector2f(10, 10));
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(1);
    box.setPosition(pos.x, pos.y);
}

void CheckBox::Update(sf::RenderWindow* window)
{
    window->draw(box);
 	check(V2(window->mapPixelToCoords(sf::Mouse::getPosition(*window))));   

    if (pressed) {
        box.setFillColor(sf::Color(HEXCOLOR(0xFF15FFFF)));
    } else {
        box.setFillColor(sf::Color(HEXCOLOR(0xFFFFFFFF)));
    }
}

void CheckBox::check(V2 mouse_pos)
{
    if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x +10 &&
        mouse_pos.y >= pos.y && mouse_pos.y <= pos.y +10) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            if (pressedTime.getElapsedTime().asSeconds() > 0.1f) {
                if (!pressed) pressed = true;
                else pressed = false;
            }
            pressedTime.restart();
        }
    }
}
