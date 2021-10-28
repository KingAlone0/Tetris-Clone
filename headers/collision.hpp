#pragma once
#include <iostream>
#include "types.hpp"

struct BoxCollision // Should be a class? probably YES
{
    unsigned short int v0, v1, v2, v3; // Should be float? YES probably
	bool hasArea = false;
	V4 playable_area;
	
    BoxCollision();
    BoxCollision(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
	
    void updateCollision(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
	
    bool checkBoxCollision(BoxCollision box);
	bool checkLimitCollision();
	bool checkGridCollision(BoxCollision box);
	
	void addAreaPlayable(float x, float y, float width, float height);
	
	/**Funcion to check collision outside class*/
    static bool checkBoxCollision(BoxCollision box0, BoxCollision box1);
};

// Usage example outside a class, and if the Box Collision wasn't initialize yet.
#if 0
{
	BoxCollision::checkBoxCollision(BoxCollision(10, 10, 10, 10), BoxCollision(15, 15, 15, 15));
}


#endif