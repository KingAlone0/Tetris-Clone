#pragma once
#include <iostream>

struct BoxCollision
{
    unsigned short int v0, v1, v2, v3; // v0 = x, v1 = x + width, v2 = y, v3 = y + height.
	
	
    BoxCollision();
    BoxCollision(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
	
    void updateCollision(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
	
    bool checkBoxCollision(BoxCollision box);
	bool checkGridCollision(BoxCollision box);
	
	/**Funcion to check collision outside class*/
    static bool checkBoxCollision(BoxCollision box0, BoxCollision box1);
};

// Usage example outside a class, and if the Box Collision wasn't initialize yet.
#if 0
{
	BoxCollision::checkBoxCollision(BoxCollision(10, 10, 10, 10), BoxCollision(15, 15, 15, 15));
}


#endif