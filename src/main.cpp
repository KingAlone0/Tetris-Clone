#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
#include "UI.hpp"
#include "button.hpp"
#include "image.hpp"
#include "keyboard.hpp"

#define TILE 16

#include "types.hpp"

int main()
{
	sf::Clock c;
	sf::RenderWindow window(sf::VideoMode(36 *TILE , 26 * TILE), "Mandioca"); // 576 x 416
	
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(36 *TILE , 26 * TILE));
	background.setPosition(0.f, 0.f);
	background.setFillColor(sf::Color::Blue);
	
	Button start(V2(10.f, 10.f), sf::IntRect(0.f, 45.f, 32.f, 16.f), 4);
	Image logo(V2(214.f, 15.f), sf::IntRect(0.f, 0.f, 40.f, 23.f), 8, .2f);
	
	Keyboard k;
	while(window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T)) {
			window.clear();
			Tetris(window);
			c.restart();
		}
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		
		start.mouseIsOver(sf::Mouse::getPosition(window));
		
		if (k.justPressed(sf::Keyboard::Key::Escape) && c.getElapsedTime().asSeconds() >= 0.2f) {
			window.close();
		}
		// ----------------------
		window.draw(background);
		window.draw(start.spr);
		logo.update();
		window.draw(logo.spr);
		
		// ----------------------
		
		window.display();
		window.clear();
	}
	return EXIT_SUCCESS;
}
