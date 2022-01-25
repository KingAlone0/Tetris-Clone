#include <SFML/Graphics.hpp>
#include "renderWindow.hpp"
#include "menu.hpp"

#define TILE 16
int ID::current_ID = 0;

int main()
{
	sf::Clock c;
	RenderWindow window("Mandioca", 36 * TILE , 26 * TILE); // 576 x 416
	
	V2 window_size(window.window.getSize().x, window.window.getSize().y);
	
    Menu(window);

	return EXIT_SUCCESS;
}

