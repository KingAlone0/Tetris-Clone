#include "animation.hpp"
#include <iostream>

Animation::Animation(sf::Sprite* spr, sf::IntRect sprPlace, int8 frames, float fps, bool repeat)
:a_spr(spr), rect(sprPlace), frames(frames), fps(fps), repeat(repeat)
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
			if (currentFrame > frames){
				currentFrame = 0;
			}
			if (currentFrame < frames) 
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

void Animation::changeFrame(int8 n_frame)
{
	if (n_frame == currentFrame)
		return;
	currentFrame = n_frame;
	if (n_frame != 0) {
		sf::IntRect next_frame = rect;
		next_frame.left += rect.width * n_frame;
		a_spr->setTextureRect(next_frame);
	}
	else if (n_frame == 0) {
		a_spr->setTextureRect(rect);
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
