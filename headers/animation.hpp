#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include <SFML/Graphics.hpp>

class Animation
{
	private:
	uint8_t currentFrame = 0;
	bool play = true;
	bool repeat;
	sf::Clock clock;
	sf::Time time;
	
	public:
	sf::Sprite* a_spr = nullptr;
	sf::IntRect rect;
	uint8_t frames = 0;
	float fps; // change to frameRate, private? and add setter and getter.
	
	public:
	Animation() {};
	Animation(sf::Sprite* spr, sf::IntRect sprPlace, uint8_t frames, float fps, bool repeat = true);
	
	void setAnimationState(bool State); //True animation play, false don't
	void setFramesPerSeconds(float n_fps) { fps = n_fps; }
	
	uint8_t getCurrentFrame() const { return currentFrame; }
	
	void update();
	
	void changeFrame(uint8_t n_frame);
	
	
	Animation& operator=(const Animation& anim);
	
	
	
	//private:
	//sf::Rect<int>[]; ? Initialize with the number of frames.
	//
};

#endif /* Animation_HPP */
