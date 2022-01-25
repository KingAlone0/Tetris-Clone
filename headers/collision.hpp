#pragma once
#include <iostream>
#include "types.hpp"

struct BoxCollision // Should be a class? probably YES
{
    unsigned short int v0, v1, v2, v3; // Should be float? YES probably
	bool hasArea = false;
	V4 playable_area;
	
    BoxCollision() {};
    BoxCollision(unsigned int x, unsigned int y, unsigned int width, unsigned int height):
        v0(x), v1(x + width), v2(y), v3(y + height) {} 


    void updateCollision(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
	
    bool checkBoxCollision(BoxCollision box);
	bool checkLimitCollision();
	bool checkGridCollision(BoxCollision box);
    bool isInside(int x, int y);
    bool isInside(V2 point) { return isInside(point.x, point.y); }
	
	void addAreaPlayable(float x, float y, float width, float height);
	
	/**Funcion to check collision outside class*/
    static bool checkBoxCollision(BoxCollision box0, BoxCollision box1);
    static bool isPointInside(BoxCollision box, V2 point);
    static bool isPointInside(int x, int y, int w, int h, V2 p) {
        return isPointInside(BoxCollision(x, y, w, h), p);
    }
    static bool isPointInside(BoxCollision box, int x, int y) {
        return isPointInside(box, V2(x, y));
    }
};
// Usage example outside a class, and if the Box Collision wasn't initialize yet.
#if 0
{
	BoxCollision::checkBoxCollision(BoxCollision(10, 10, 10, 10), BoxCollision(15, 15, 15, 15));
}


#endif

