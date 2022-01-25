#include "menu.hpp"

void Menu(RenderWindow &window)
{
    sf::Clock c;
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(36 *TILE , 26 * TILE));
	background.setPosition(0.f, 0.f);
	background.setFillColor(sf::Color::Blue);
	
	Button start(V2(232.f, 133.f), sf::IntRect(0.f, 26.f, 32.f, 16.f), 4, .2f, sf::IntRect(0.f, 223.f, 9.f, 9.f));
	Button options(V2(232.f, 216.f), sf::IntRect(0.f, 26.f, 32.f, 16.f), 4, .2f, sf::IntRect(0.f, 239.f, 9.f, 9.f));
	Image logo(V2(214.f, 15.f), sf::IntRect(0.f, 0.f, 40.f, 23.f), 8, .2f);
    logo.setScale(3.2f);
    options.setScale(3.f);
    start.setScale(3.f);
	{ // Play Button
		std::function<void()> fncPtr = [&window] () { Tetris(window); };
		start.setOnReleasedFunction(fncPtr);
	}
	{ // Options Button
        
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
		while (window.window.pollEvent(event))
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
		logo.Update(&window);
		
		
		start.Update(&window);
		options.Update(&window);
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
}
