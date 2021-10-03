#include "keyboard.hpp"
#include <iostream>

#define delay .2f
// NOTE(AloneTheKing): The movemente is kind werdly, and if pressed both key he don't move smoothly
bool Keyboard::checkInput(sf::Keyboard::Key k)
{
	if (!sf::Keyboard::isKeyPressed(k))
		return false; // If the key wasn't pressed just return false.
	
	lastTimePressed = timer.getElapsedTime();
	/* Check if other key has been pressed in less than delay time, if true reset the moves and return false */
	pressed = lastTimePressed.asSeconds() <= delay ? true : false; 
	if (pressed && moves < 3 && lastKeyPressed != k) {
		moves = 0;
		return false;
	}
	
	if (lastKeyPressed == k) 
	{
		if (moves < 3 && lastTimePressed.asSeconds() <= delay) {
			return false;
		}
		else
		{
			if (lastTimePressed.asSeconds() <= .1f) 
			{
				if (lastTimePressed.asSeconds() == .1f){
					timer.restart();
				}
				return false;
			}
		}
	}
	
	timer.restart();
	if (lastKeyPressed != k)
		moves = 0;
	
	else
		moves++;
	
	lastKeyPressed = k;
	return true;
}

bool Keyboard::justPressed(sf::Keyboard::Key k)
{
	if (!sf::Keyboard::isKeyPressed(k)) {
		return false;
	}
	
	lastTimePressed = timer.getElapsedTime();
	
	if (lastTimePressed.asSeconds() <= 0.07f) {
		timer.restart();
		return false;
	}
	
	timer.restart();
	return true;
}

// NOTE(AloneTheKing): DAS is kinda implemented, but need to choose the values of the delay