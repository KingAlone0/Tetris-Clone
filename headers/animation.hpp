#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include <SFML/Graphics.hpp>

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
	float fps; // change to frameRate, private? and add setter and getter.
	
	public:
	Animation() {};
	Animation(sf::Sprite* spr, sf::IntRect sprPlace, int8 frames, float fps, bool repeat = true);
	
	void setAnimationState(bool State); //True animation play, false don't
	void setFramesPerSeconds(float n_fps) { fps = n_fps; }
	
	uint8_t getCurrentFrame() const { return currentFrame; }
	
	void update();
	
	void changeFrame(int8 n_frame);
	
	
	Animation& operator=(const Animation& anim);
	
	
	
	//private:
	//sf::Rect<int>[]; ? Initialize with the number of frames.
	//
};

#endif /* Animation_HPP */
