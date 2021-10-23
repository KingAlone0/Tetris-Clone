#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "UI.hpp"
#include "animation.hpp"

class Button : public UI
{
	private:
	Animation anim;
	bool pressed = false;
	unsigned short int frames;
	float frameRate;
	
	
	
	public:
	Button();
	Button(V2 position, sf::IntRect sprPlace, unsigned short int frames = 0, float frameRate = .2f);
	bool getPressed() const { return pressed; };
	
	// void Update(sf::RenderWindow& window) override;
	
	void mouseIsOver(V2 mousePos);
	private:
	bool buttonPressed(V2 mousePos);
	
};


#endif /* Button_HPP */