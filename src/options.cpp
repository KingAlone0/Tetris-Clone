#include "options.hpp"
#include "slider.hpp"
#include "types.hpp"

void Options(sf::RenderWindow& window)
{
	sf::RectangleShape background(sf::Vector2f(window.getSize()));
	background.setFillColor(sf::Color(HEXCOLOR(0x252525FF)));
	
	Slider slider(16.f, 32.f, 100.f, 10.f);
	
	//Slider t_slider(200.f, 32.f, 100.f, 6.f);
	
	
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
		//t_slider.Update(&window);
		
		window.display();
		window.clear();
	}
	
}