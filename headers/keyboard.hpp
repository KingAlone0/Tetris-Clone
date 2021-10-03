#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP
#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>


class Keyboard
{
	private:
	sf::Clock timer;
	sf::Time lastTimePressed;
	sf::Keyboard::Key lastKeyPressed;
	bool pressed;
	
	unsigned char moves = 0;
	public:
	Keyboard() { timer.restart(); }
	
	bool checkInput(sf::Keyboard::Key k);
	
	sf::Time getTimer() const { return timer.getElapsedTime(); }
	void reset() { timer.restart(); }
	private:
	
	
	// ----------Test*
	public:
	bool justPressed(sf::Keyboard::Key k); // This fuction only return true, if the timer > 0.07, this mean that don't returns if the key still pressed.
	// ----------
	
	
};


#endif /* Keyboard_HPP */