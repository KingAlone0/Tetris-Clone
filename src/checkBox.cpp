#include "checkBox.hpp"

CheckBox::CheckBox(float x, float y)
{
    pos.x = x;
    pos.y = y;
    setBox();
    pressedTime.restart();
    id = ID(ID_TYPE::CHECK_BOX);
}

void CheckBox::setBox()
{
    box.setSize(sf::Vector2f(10, 10));
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(1);
    box.setPosition(pos.x, pos.y);
}

void CheckBox::Update(RenderWindow* window)
{
    window->draw(box);
 	check(window->getMousePosition());

    if (pressed) {
        box.setFillColor(sf::Color(HEXCOLOR(0xFF15FFFF)));
    } else {
        box.setFillColor(sf::Color(HEXCOLOR(0xFFFFFFFF)));
    }
}

void CheckBox::check(V2 mouse_pos)
{
    if (Mouse::isActive()) {
        if (Mouse::getID().id != id.id) {
            return;
        }
    }
    if (BoxCollision::isPointInside(BoxCollision(pos.x, pos.y, 10, 10), mouse_pos)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            if (pressedTime.getElapsedTime().asSeconds() > 0.1f) {
                if (!pressed) {
                    Mouse::setActive(id);
                    pressed = true;
                }
                else {
                    pressed = false;
                }
            }
            pressedTime.restart();
        } else {
            Mouse::setInactive();
        }
    }
}

