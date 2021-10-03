#include "UI.hpp"
#include <iostream>

UI::UI()
{
	rect.setSize(sf::Vector2f(150.f, 50.f));
	rect.setFillColor(sf::Color::Green);
}


void UI::mouseIsOver(sf::RenderWindow& window)
{
	sf::Vector2f m  = sf::Vector2f(sf::Mouse::getPosition(window));
	sf::Vector2f r = rect.getSize();
	
	if (m.x >= rect.getPosition().x && m.x <= rect.getPosition().x + r.x)
	{
		if (m.y >= rect.getPosition().y && m.y <= rect.getPosition().y + r.y)
		{
			rect.setFillColor(sf::Color::Red);
		}
		else {
			rect.setFillColor(sf::Color::Green);
		}
	}
	else {
		rect.setFillColor(sf::Color::Green);
	}
}
