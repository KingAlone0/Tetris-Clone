#include "UI.hpp"
#include <iostream>

UI::UI()
{
	if (!texture.loadFromFile("../textures/sprite-sheets.png"))// TODO(AloneTheKing): Need to make a way to set this outside the class, if want to load other sheet, whitout changing here, maybe turn static 
		return;
	rect.setSize(sf::Vector2f(150.f, 50.f));
	rect.setFillColor(sf::Color::Green);
}

UI::UI(V2 position, sf::IntRect sprPlace): position(position), sprPlace(sprPlace)
{
	if (!texture.loadFromFile("../textures/sprite-sheets.png"))// TODO(AloneTheKing): Need to make a way to set this outside the class, if want to load other sheet, whitout changing here, maybe turn static 
		return;
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
