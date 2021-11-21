#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "UI.hpp"
#include "animation.hpp"
#include <functional>
// float frame = 0.017 seconds
class Button : public UI
{
	private:
	sf::Clock c;
	sf::Sprite icon;
	Animation anim;
	bool pressed = false;
	float last_pressed = 0.f;
	unsigned short int frames;
	float frame_rate;
	
	std::function<void()> onReleased;
	
	
	public:
	Button();
	Button(V2 position, sf::IntRect sprPlace, unsigned short int frames = 0, float frame_rate = .2f, sf::IntRect icon_place = sf::IntRect(0, 0, 0, 0));
	bool getPressed() const { return pressed; };
	void Update(sf::RenderWindow& window);
	
	sf::Sprite getIcon() const { return icon; }
	
	void setOnReleasedFunction(std::function<void()> function) { onReleased = function; }
	
	// void Update(sf::RenderWindow& window) override;
	
	
	void mouseIsOver(V2 mousePos);
	private:
	bool buttonPressed(V2 mousePos);
	bool buttonSelected(V2 mousePos);
	
};


#endif /* Button_HPP */
