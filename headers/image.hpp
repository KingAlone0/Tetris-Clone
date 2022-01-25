#ifndef IMAGE_HPP
#define IMAGE_HPP
#include "UI.hpp"
#include "animation.hpp"

class Image : public UI
{
	private:
	Animation anim;
    float scale;
	
	public:
	Image();
	Image(V2 position, sf::IntRect sprPlace);
	Image(V2 position, sf::IntRect sprPlace, uint8_t frames, float frameRate);
	
	
	void Update(RenderWindow* window) override;
	void setScale(float scale);
};

#endif /* Image_HPP */
