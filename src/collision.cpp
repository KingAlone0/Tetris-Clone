#include "collision.hpp"

BoxCollision::BoxCollision()
{
}
BoxCollision::BoxCollision(unsigned int x, unsigned int y, unsigned int width, unsigned int height):
v0(x), v1(x + width), v2(y), v3(y + height)
{
}

bool BoxCollision::checkBoxCollision(BoxCollision box)
{
    if (v0 >= box.v0 && v0 <= box.v1 - 16) {
        if(v2 >= box.v2 && v2 <= box.v3 - 16) { 
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
