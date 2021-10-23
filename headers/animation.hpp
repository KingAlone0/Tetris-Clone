#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include <SFML/Graphics.hpp>
#include <memory>

typedef uint8_t int8;

class Animation
{
	private:
	int8 currentFrame = 0;
	bool play = true;
	bool repeat;
	sf::Clock clock;
	sf::Time time;
	
	public:
	sf::Sprite* a_spr = nullptr;
	sf::IntRect rect;
	int8 frames = 0;
	float fps;
	
	public:
	Animation() {};
	Animation(sf::Sprite* spr, sf::IntRect sprPlace, int8 frames, float fps, bool repeat = true);
	
	void setAnimationState(bool State); //True animation play, false don't
	void setFramesPerSeconds(float n_fps) { fps = n_fps; }
	
	void update();
	
	void changeFrame(int8 n_frame);
	
	
	Animation& operator=(const Animation& anim);
	
};

#endif /* Animation_HPP */