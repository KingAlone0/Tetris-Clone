#ifndef UI_HPP
#define UI_HPP
#include <SFML/Graphics.hpp>
#include "types.hpp"

class UI
{
	protected:
	sf::RectangleShape rect;
	sf::IntRect sprPlace;
	sf::Texture texture;
	
	public:
	V2 position;
	sf::Sprite spr;
	
	
	public:
	UI();
	UI(V2 position, sf::IntRect sprPlace);
	sf::RectangleShape getRectangle() const { return rect; }
	sf::Sprite getSprite() const { return spr; }
	//virtual void Update(sf::RenderWindow& window ) {};
	
	void mouseIsOver(sf::RenderWindow& window);
	//make a function to know when click on the button. Maybe a Button class? Or it's too much?
	
};



#endif /* UI_HPP */