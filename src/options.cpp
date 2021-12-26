#include "options.hpp"

void Options(sf::RenderWindow& window)
{
	sf::RectangleShape background(sf::Vector2f(window.getSize()));
	background.setFillColor(sf::Color(HEXCOLOR(0x252525FF)));
	
	Slider slider(16.f, 32.f, 100.f, 10.f);
    CheckBox check(16.f, 50.f);
	
	
    bool draggin_grip = false;
	bool quit = false;
	while (!quit)
	{
		window.draw(background);
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				quit = true;
				window.close();
			}
		}
		slider.Update(&window);
        check.Update(&window);
		
		window.display();
		window.clear();
	}
	
}

