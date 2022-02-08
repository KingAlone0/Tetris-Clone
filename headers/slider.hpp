#ifndef SLIDER_HPP
#define SLIDER_HPP

#include "UI.hpp"
#include "configs.hpp"

class Slider : public UI
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
	sf::Texture texture;
	
	sf::Sprite slider_body;
	sf::Sprite grip_body;
	
	bool draggin_grip;
	float slider_range;
	float value = 0.f;
    float* ptr_value;
    float m_scale;
    ID id;
	
	private:
	void changeGripPosition(V2 mouse_pos);
	void createSlider();
	void createGrip();
    void setGripToValue();
	
	public:
	Slider();
	Slider(float x, float y, float width, float height);
	Slider(float x, float y, float width, float height, uint8_t a);
	
	void setGripSize(float width, float height);
    float getValue() { return value; }
    void setValueTo(float* adrsToPtr, float scale = 1);
	
    void Update(RenderWindow* window);
};

#endif

