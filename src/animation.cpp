#include "animation.hpp"
#include <iostream>

Animation::Animation(sf::Sprite* spr, sf::IntRect sprPlace, int8 frames, float fps = 0.2f)
:a_spr(spr), rect(sprPlace), frames(frames), fps(fps)
{
	clock.restart();
}


void Animation::update()
{
	time = clock.getElapsedTime();
	if (time.asSeconds() > fps)
	{
		if (frames > 0)
		{
			currentFrame++;
			if ((int)currentFrame > frames){
				currentFrame = 0;
			}
			if ((int)currentFrame < frames) 
			{
				sf::IntRect n_frame(a_spr->getTextureRect());
				n_frame.left += rect.width;
				a_spr->setTextureRect(n_frame);
			}
			if ((int)currentFrame == 0) {
				a_spr->setTextureRect(rect);
			}
			clock.restart();
		}
	}
}

void Animation::setAnimationState(bool State)
{
	play = State;
}



Animation& Animation::operator=(const Animation& anim)
{
	if (this == &anim)
		return *this;
	
	this->a_spr = anim.a_spr;
	this->rect = anim.rect;
	this->frames = anim.frames;
	this->fps = anim.fps;
	
	return *this;
}
