#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
#include "options.hpp"
#include "UI.hpp"
#include "button.hpp"
#include "image.hpp"
#include "keyboard.hpp"

#define TILE 16

#include "types.hpp"
#include <functional>

#include "renderWindow.hpp"

int main()
{
	sf::Clock c;
	RenderWindow window("Mandioca", 36 * TILE , 26 * TILE); // 576 x 416
	
	V2 window_size(window.getSize().x, window.getSize().y);
	float aspect_ratio = 576 / 416;
	sf::View view = window.getView();
	
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(36 *TILE , 26 * TILE));
	background.setPosition(0.f, 0.f);
	background.setFillColor(sf::Color::Blue);
	
	Button start(V2(10.f, 10.f), sf::IntRect(0.f, 26.f, 32.f, 16.f), 4, .2f, sf::IntRect(0.f, 223.f, 9.f, 9.f));
	Button options(V2(10.f, 100.f), sf::IntRect(0.f, 26.f, 32.f, 16.f), 4, .2f, sf::IntRect(0.f, 223.f, 9.f, 9.f));
	Image logo(V2(214.f, 15.f), sf::IntRect(0.f, 0.f, 40.f, 23.f), 8, .2f);
	// Play Button
	{
		std::function<void()> fncPtr = [&window] () { Tetris(window); };
		start.setOnReleasedFunction(fncPtr);
	}
	// Options Button
	{
		std::function<void()> fcnPtr = [&window] () { Options(window); };
		options.setOnReleasedFunction(fcnPtr);
	}
	
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
		
		
		
		if (k.justPressed(sf::Keyboard::Key::Escape) && c.getElapsedTime().asSeconds() >= 0.2f) {
			window.close();
		}
		// ----------------------
		window.draw(background);
		logo.update();
		window.draw(logo.spr);
		
		
		start.Update(window);
		options.Update(window);
		// ----------------------
		/*
		// Preserve Aspect ratio
		if (window.getSize().x != window_size.x || window.getSize().y != window_size.y) 
		{
			view.setSize((float)window.getSize().x, (float)window.getSize().y);
			if ((double)window.getSize().x / window.getSize().y == aspect_ratio)  {
				view = window.getDefaultView(); // don't that, need to pick up last aspect useful
				std::cout << window.getSize().x << " : " << window.getSize().y << std::endl;
			}
			window.setView(view);
			window_size = sf::Vector2f(window.getSize());
		}
		
		
		*/
		window.display();
		window.clear();
	}
	return EXIT_SUCCESS;
}
