#include "button.hpp"
#include <iostream>

Button::Button(V2 position, sf::IntRect sprPlace, unsigned short int frames, float frame_rate, sf::IntRect icon_place): UI(position, sprPlace), frames(frames), frame_rate(frame_rate)
{
	anim = Animation(&spr, sprPlace, frames, frame_rate, false);
	spr.setTexture(texture);
	
	if (icon_place.width != 0) {
		icon.setTexture(texture);
		icon.setTextureRect(icon_place);
		icon.setPosition(position.x + 4.f, position.y + 1);
		icon.scale(2.f, 2.f);
	}
	
	spr.setTextureRect(sprPlace);
	spr.setPosition(position.x, position.y);
	spr.scale(2.f, 2.f);
	c.restart();
}

void Button::Update(sf::RenderWindow& window)
{
	V2 mouse_pos(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
	mouseIsOver(mouse_pos);
	buttonPressed(mouse_pos);
	
	window.draw(spr);
	window.draw(icon);
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
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && buttonSelected(mousePos))
	{
		if (frames > 0) {
			anim.changeFrame(2);
			icon.setPosition(spr.getPosition().x + 4.f, spr.getPosition().y + 5);
			last_pressed = c.getElapsedTime().asSeconds();
			pressed = true;
			return true;
		}
		
	}
	else if (pressed && buttonSelected(mousePos)) 
	{
		icon.setPosition(spr.getPosition().x + 4.f, spr.getPosition().y + 1);
		anim.changeFrame(0);
		pressed = false;
		onReleased();
	}
	else if (pressed && !buttonSelected(mousePos)) 
	{
		icon.setPosition(spr.getPosition().x + 4.f, spr.getPosition().y + 1);
		pressed = false;
		anim.changeFrame(0);
	}
	return false;
}

bool Button::buttonSelected(V2 mousePos)
{
	sf::FloatRect sprBounds(spr.getGlobalBounds());
	
	if (mousePos.x >= spr.getPosition().x && mousePos.x <= spr.getPosition().x + sprBounds.width)
	{
		if (mousePos.y >= spr.getPosition().y && mousePos.y <= spr.getPosition().y + sprBounds.height)
		{
			return true;
		}
	}
	return false;
}
