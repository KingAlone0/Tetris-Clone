#ifndef IMAGE_HPP
#define IMAGE_HPP
#include "UI.hpp"
#include "animation.hpp"

class Image : public UI
{
	private:
	Animation anim;
	
	public:
	Image();
	Image(V2 position, sf::IntRect sprPlace);
	Image(V2 position, sf::IntRect sprPlace, uint8_t frames, float frameRate);
	
	
	void update();
	void setScale(V2 Scale);
};

#endif /* Image_HPP */
