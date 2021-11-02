#include "button.hpp"
#include <iostream>

Button::Button(V2 position, sf::IntRect sprPlace, unsigned short int frames, float frameRate): UI(position, sprPlace), frames(frames), frameRate(frameRate)
{
	anim = Animation(&spr, sprPlace, frames, frameRate, false);
	spr.setTexture(texture);
	
	
	spr.setTextureRect(sprPlace);
	spr.setPosition(position.x, position.y);
	spr.scale(2.f, 2.f);
}

void Button::Update(sf::RenderWindow& window)
{
	V2 mouse_pos(sf::Mouse::getPosition(window));
	mouseIsOver(mouse_pos);
	buttonPressed(mouse_pos);
	
	window.draw(spr);
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
	if (buttonSelected(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (frames > 0) {
			anim.changeFrame(2);
			pressed = true;
			return true;
		}
	}
	else if (pressed == true) {
		anim.changeFrame(0);
		pressed = false;
	}
	
	return false;
}

bool Button::buttonSelected(V2 mousePos)
{
	sf::FloatRect sprBounds(spr.getGlobalBounds());
	
	if (mousePos.x >= spr.getPosition().x && mousePos.x <= spr.getPosition().x + sprBounds.width)
	{
		if (mousePos.y >= spr.getPosition().x && mousePos.y <= spr.getPosition().y + sprBounds.height)
		{
			return true;
		}
	}
	return false;
}