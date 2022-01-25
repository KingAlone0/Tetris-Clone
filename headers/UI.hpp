#ifndef UI_HPP
#define UI_HPP
#include <SFML/Graphics.hpp>
#include "types.hpp"
#include "collision.hpp" 
#include "renderWindow.hpp"
#include "mouse.hpp"
#include "handleErrors.hpp"

class UI
{
    private:
	BoxCollision collision;

	protected:
	sf::RectangleShape rect;
	sf::IntRect sprPlace;
	sf::Texture texture;
	V2 pos;
	sf::Sprite spr;

	
	public:
	UI();
	UI(V2 pos, sf::IntRect sprPlace);
    UI(V2 pos, sf::IntRect sprPlace, bool test);
    UI(V2 pos, float width, float height);

	sf::RectangleShape getRectangle() const { return rect; }
	sf::Sprite getSprite() const { return spr; }
    bool isPointInside(int x, int y);
    bool isPointInside(V2 point) { return isPointInside(point.x, point.y); }
    void setCollision(int x, int y, int w, int h);
    
	
	void mouseIsOver(RenderWindow& window);

	virtual void Update(RenderWindow* window){};
    virtual void setScale(float scale);
};



#endif /* UI_HPP */

