#include "collision.hpp"

BoxCollision::BoxCollision()
{
}
BoxCollision::BoxCollision(unsigned int x, unsigned int y, unsigned int width, unsigned int height):
v0(x), v1(x + width), v2(y), v3(y + height)
{
}

bool BoxCollision::checkLimitCollision()
{
	if (hasArea) {
		if (v0 <= playable_area.x || v1 >= playable_area.x + playable_area.width || v2 <= playable_area.y || v2 >= playable_area.y + playable_area.height) {
			return true;
		}
	}
	return false;
}

bool BoxCollision::checkBoxCollision(BoxCollision box)
{
    if (v0 >= box.v0 && v0 <= box.v1 - 16) {
        if(v2 >= box.v2 && v2 <= box.v3 - 16) { 
            return true;
        }
    }
	if (hasArea) {
		if (v0 <= playable_area.x || v1 >= playable_area.x + playable_area.width || v2 <= playable_area.y || v2 >= playable_area.y + playable_area.height) {
			return true;
		}
	}
    return false;
}

bool BoxCollision::checkBoxCollision(BoxCollision box0, BoxCollision box1)
{
    if (box0.v0 >= box1.v0 && box0.v0 <= box1.v1)
    {
        if(box0.v2 >= box1.v2 && box0.v2 <= box1.v3){
            return true;
        }
    }
    return false;
}

bool BoxCollision::checkGridCollision(BoxCollision box) // Implement this
{
	return false;
}

void BoxCollision::updateCollision(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
    v0 = x;
    v1 = x + width;
    v2 = y;
    v3 = y + height;
}

void BoxCollision::addAreaPlayable(float x, float y, float width, float height)
{
	hasArea = true;
	playable_area.x = x;
	playable_area.y = y;
	playable_area.width = width;
	playable_area.height = height;
}