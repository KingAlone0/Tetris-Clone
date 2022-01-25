#include "button.hpp"
#include <iostream>

Button::Button(V2 pos, sf::IntRect sprPlace, unsigned short int frames, float frame_rate, sf::IntRect icon_place): 
    UI(pos, sprPlace), frames(frames), frame_rate(frame_rate)
{
	anim = Animation(&spr, sprPlace, frames, frame_rate, false);
	spr.setTexture(texture);
	
	if (icon_place.width != 0) {
		icon.setTexture(texture);
		icon.setTextureRect(icon_place);
		icon.setPosition(pos.x + 4.f, pos.y + 1);
		icon.scale(2.f, 2.f);
	}
    id = ID(ID_TYPE::BUTTON);
	
	spr.setTextureRect(sprPlace);
	spr.setPosition(pos.x, pos.y);
	spr.scale(2.f, 2.f);
    setCollision(pos.x, pos.y, spr.getGlobalBounds().width, spr.getGlobalBounds().height);
	c.restart();
}

void Button::Update(RenderWindow* window)
{
    V2 mouse_pos = window->getMousePosition();
	mouseIsOver(mouse_pos);
	buttonPressed(mouse_pos);
	window->draw(spr);
	window->draw(icon);
}

void Button::mouseIsOver(V2 mousePos)
{
	if (buttonSelected(mousePos)) 
	{
		if (frames > 0) {
			anim.changeFrame(1);
		}
	}
	else {
		anim.changeFrame(0);
	}
}

bool Button::buttonPressed(V2 mousePos)
{
    if (Mouse::isActive())
    {
        if (Mouse::getID().id != id.id) {
            return false;
        }
    }
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && buttonSelected(mousePos))
	{
		if (frames > 0) {
			anim.changeFrame(2);
			icon.setPosition(spr.getPosition().x + 4.f, spr.getPosition().y + 5);
			last_pressed = c.getElapsedTime().asSeconds();
			pressed = true;
            Mouse::setActive(id);
			return true;
		}
		
	}
	else if (pressed && buttonSelected(mousePos)) 
	{
		icon.setPosition(spr.getPosition().x + 4.f, spr.getPosition().y + 1);
		anim.changeFrame(0);
        Mouse::setInactive();
		pressed = false;
		onReleased();
	}
	else if (pressed && !buttonSelected(mousePos)) 
	{
		icon.setPosition(spr.getPosition().x + 4.f, spr.getPosition().y + 1);
        Mouse::setInactive();
		pressed = false;
		anim.changeFrame(0);
	}
	return false;
}

bool Button::buttonSelected(V2 mousePos)
{
    return isPointInside(mousePos.x, mousePos.y);
}

void Button::setScale(float scale)
{
    spr.setScale(scale, scale);
    icon.setScale(scale, scale);
    setCollision(pos.x, pos.y, spr.getGlobalBounds().width, spr.getGlobalBounds().height);
}


