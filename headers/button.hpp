#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "UI.hpp"
#include "animation.hpp"
#include <functional>
#include "sound.hpp"
#include "configs.hpp"
#include "text.hpp"

#include <type_traits>
#include <cstdlib>
#include <memory>
#include <cxxabi.h>

template <typename T>
bool check_arg(T);

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
    ID id;
    Text m_name;

    struct {
        const sf::IntRect sprPlace   = sf::IntRect(0.f, 26.f, 32.f, 16.f);
        const sf::IntRect icon_place = sf::IntRect(0.f, 223.f, 9.f, 9.f);
    } default_value;

    struct {
        sf::Time trigger;
    } timer;

	std::function<void()> onReleased;
    bool m_function = false;
    bool m_trigger = false;
	
	
	public:
	Button();
	Button(V2 position, sf::IntRect sprPlace, unsigned short int frames = 0, 
            float frame_rate = .2f, sf::IntRect icon_place = sf::IntRect(0, 0, 0, 0), const std::string& _text = "nil");
    Button(V2 position, unsigned short int frames = 4, float frame_rate = 0.2f);
    Button(V2 position, const std::string& _text, unsigned short int frames = 4, float frame_rate = 0.2f);


	sf::Sprite getIcon() const { return icon; }
    
    void setOnReleasedFunction(const std::function<void()>& _fnc);
	
    void Update(RenderWindow* window) override;
    void setScale(float scale) override;
    void setName(const std::string name);

    
    bool hasTriggered() { return m_trigger; }


	
	void mouseIsOver(V2 mousePos);
	private:
	bool buttonPressed(V2 mousePos);
	bool buttonSelected(V2 mousePos);

    template <class T>
    std::string type_name();

};


#endif /* Button_HPP */
