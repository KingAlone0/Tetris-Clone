#ifndef UI_HPP
#define UI_HPP
#include <SFML/Graphics.hpp>

struct V2
{
	float x = 0, y = 0;
	
	V2() {}
	V2(float x, float y): x(x), y(y) {}
	V2(sf::Vector2f vector): x(vector.x), y(vector.y) {}
	V2(sf::Vector2i vector): x((float)vector.x), y((float)vector.y) {}
	
	V2& operator=(const V2& vector) {
		if (this == &vector)
			return *this;
		this->x = vector.x;
		this->y = vector.y;
		return *this;
	}
	V2& operator=(const sf::Vector2f& vector) {
		this->x = vector.x;
		this->y = vector.y;
		return *this;
	}
	V2& operator-(V2& vector) {
		if (this == &vector)
			return *this;
		this->x -= vector.x;
		this->y -= vector.y;
		
		return *this;
	}
	
};

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