#include "keyboard.hpp"
#include <iostream>

sf::Clock Keyboard::timer_st;
sf::Time  Keyboard::lastTimePressed_st;

#define delay .1f
// NOTE:  Need to have better times to handle the movements, is kinda slow compared with the jstris 
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
			if (lastTimePressed.asSeconds() <= .05f) 
			{
				if (lastTimePressed.asSeconds() == .05f){
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

bool Keyboard::justPressedGlobal(sf::Keyboard::Key k)
{
	if (!sf::Keyboard::isKeyPressed(k)) {
		return false;
	}
	
	lastTimePressed_st = timer_st.getElapsedTime();
	
	if (lastTimePressed_st.asSeconds() <= 0.07f) {
		timer_st.restart();
		return false;
	}
	
	timer_st.restart();
	return true;
}

