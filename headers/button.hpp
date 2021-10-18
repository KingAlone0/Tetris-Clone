#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "UI.hpp"
#include "animation.hpp"

class Button : public UI
{
	private:
	bool pressed = false;
	Animation anim;
	
	public:
	Button();
	Button(V2 position, sf::IntRect sprPlace);
	bool getPressed() const { return pressed; };
	
	// void Update(sf::RenderWindow& window) override;
	
	
	private:
	void mouseIsOver(V2 mousePos);
	bool buttonPressed(V2 mousePos);
	
};


#endif /* Button_HPP */