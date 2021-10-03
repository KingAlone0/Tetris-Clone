#ifndef UI_CPP
#define UI_CPP
#include <SFML/Graphics.hpp>

class UI
{
	private:
	sf::RectangleShape rect;
	
	
	
	public:
	UI();
	sf::RectangleShape getRectangle() const { return rect; }
	
	void mouseIsOver(sf::RenderWindow& window);
};



#endif /* UI_CPP */