#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include <SFML/Graphics.hpp>

typedef uint8_t int8;

class Animation
{
	private:
	int8 currentFrame = 0;
	bool play = true;
	sf::Clock clock;
	sf::Time time;
	
	
	public:
	//sf::Texture* texture = nullptr;
	sf::Sprite* a_spr = nullptr;
	sf::IntRect rect;
	int8 frames = 0;
	float fps = 0.2f;
	
	public:
	Animation() {};
	Animation(sf::Sprite* spr, sf::IntRect sprPlace, int8 frames, float fps);
	
	void setAnimationState(bool State); //True animation play, false don't
	void setFramesPerSeconds(float n_fps) { fps = n_fps; }
	
	void update();
	
	Animation& operator=(const Animation& anim);
	
};

#endif /* Animation_HPP */