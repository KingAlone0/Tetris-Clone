#include "image.hpp"
#include <iostream>
Image::Image()
{
}

Image::Image(V2 position, sf::IntRect sprPlace): UI(position, sprPlace)
{
	anim = Animation(&spr, sprPlace, 8, .2f);
	spr.setTexture(texture);
	
	spr.setTextureRect(sprPlace);
	spr.setPosition(position.x, position.y);
	spr.setScale(3.f, 3.f);
}

Image::Image(V2 position, sf::IntRect sprPlace, uint8_t frames, float frameRate)
{
	anim = Animation(&spr, sprPlace, frames, frameRate);
	spr.setTexture(texture);
	
	spr.setTextureRect(sprPlace);
	spr.setPosition(position.x, position.y);
}

void Image::update()
{
	anim.update();
}

void Image::setScale(V2 Scale)
{
	spr.setScale(Scale.x, Scale.y);
}