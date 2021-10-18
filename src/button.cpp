#include "button.hpp"
Button::Button(V2 position, sf::IntRect sprPlace): UI(position, sprPlace)
{
	anim = Animation(&spr, sprPlace, 2, .2f);
	spr.setTexture(texture);
	
	// position = V2(position.x, position.y);
	
	spr.setTextureRect(sprPlace);
	spr.setPosition(position.x, position.y);
}