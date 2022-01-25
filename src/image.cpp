#include "image.hpp"
#include <iostream>
Image::Image()
{
}

Image::Image(V2 position, sf::IntRect sprPlace): UI(position, sprPlace)
{
	anim = Animation(&spr, sprPlace, 8, .2f);
	spr.setTexture(texture);
	
    scale = 6.f;

	spr.setTextureRect(sprPlace);
	spr.setPosition(position.x, position.y);
	spr.setScale(scale, scale);
}

Image::Image(V2 position, sf::IntRect sprPlace, uint8_t frames, float frameRate)
{
	anim = Animation(&spr, sprPlace, frames, frameRate);
	spr.setTexture(texture);
	
	spr.setTextureRect(sprPlace);
    spr.setPosition(position.x, position.y);
}

void Image::Update(RenderWindow* window)
{
	anim.update();
    window->draw(spr);
}

void Image::setScale(float Scale)
{
    scale = Scale;
	spr.setScale(scale, scale);
}
