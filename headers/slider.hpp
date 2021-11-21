#ifndef SLIDER_HPP
#define SLIDER_HPP
#include "UI.hpp"



class Slider
{
	private:
	typedef struct {
		float x, y, width, height;
	} m_slider;
	
	typedef struct {
		float x = 12.f, y = 31.f, width = 8.f, height = 10.f, min, max;
	} m_grip;
	
	m_slider slider;
	m_grip grip;
	sf::Texture texture; // --
	
	sf::Sprite slider_body;
	sf::Sprite grip_body;
	
	bool draggin_grip;
	float slider_range;
	float value = 0.f;
	
	private:
	void changeGripPosition(V2 mouse_pos);
	void createSlider();
	void createGrip();
	
	public:
	Slider();
	Slider(float x, float y, float width, float height);
	Slider(float x, float y, float width, float height, uint8_t a);
	
	void setGripSize(float width, float height);
	
	void Update(sf::RenderWindow* window);
};



#endif