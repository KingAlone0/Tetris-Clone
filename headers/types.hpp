#pragma once
#ifndef TYPES_HPP
#define TYPES_HPP

#include <SFML/Graphics.hpp>

#define HEXCOLOR(code) \
((code) >> (3 * 8)) & 0xFF, \
((code) >> (2 * 8)) & 0xFF, \
((code) >> (1 * 8)) & 0xFF, \
((code) >> (0 * 8)) & 0xFF

enum TilesType
{
    I,
    J,
    L,
    O,
    S,
    T,
    Z,
    Grid,
	None
};

enum class Directions
{
	Left = 0,
	Right = 1,
	Down = 2,
	Up = 3,
	None = 9
};

inline float r_up(float val)
{
    int result = (long)(val * 100 + .5) / 100;

    return result;
}

struct Index 
{
	unsigned short int i, x, y, based;
	
	
	Index() {}
	Index(unsigned short int  i): i(i) {
		updateCoordinates();
	}
	Index (unsigned short int i, unsigned short int based): i(i), based(based) {
		updateCoordinates();
	}
	
	Index& operator=(const Index& index)
	{
		if (this == &index)
			return *this;
		this->i = index.i;
		updateCoordinates();
		
		return *this;
	}
	
	void updateCoordinates()
	{
		if (based == 4)
		{
			unsigned short int test[4][4] = { {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15} };
			for (int n = 0; n < 4; ++n) {
				for (int t = 0; t < 4; ++t) {
					if (test[n][t] == i) {
						x = t;
						y = n;
					}
				}
				
			}
		}
		else if (based == 3)
		{
			unsigned short int test[3][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8} };
			for (int n = 0; n < 3; ++n) {
				for (int t = 0; t < 3; ++t) {
					if (test[n][t] == i) {
						x = t;
						y = n;
					}
				}
			}
		}
	}
};

struct V2
{
	float x = 0, y = 0;
	
	V2() {}
	V2(float x, float y): x(x), y(y) {}
	V2(sf::Vector2f vector): x(vector.x), y(vector.y) {}
	V2(sf::Vector2i vector): x((float)vector.x), y((float)vector.y) {}
	V2(const V2& vector): x(vector.x), y(vector.y) {}
	
	V2& operator=(const V2& vector) {
		if (this == &vector)
			return *this;
		this->x = vector.x;
		this->y = vector.y;
		return *this;
	}
	V2& operator=(const sf::Vector2f& vector) {
		this->x = vector.x;
		this->y = vector.y;
		return *this;
	}
	V2& operator-(V2& vector) {
		if (this == &vector)
			return *this;
		this->x -= vector.x;
		this->y -= vector.y;
		
		return *this;
	}
	V2& operator*(short int mp) {
		this->x = x * mp;
		this->y = y * mp;
		
		return *this;
	}
	
	bool operator==(const V2& vector) {
		return (this->x == vector.x) && (this->y == vector.y);
	}
	bool operator==(const sf::Vector2f vector) {
		return (this->x == vector.x) && (this->y == vector.y);
	}
	bool operator!=(const sf::Vector2f vector) {
		return (this->x != vector.x) && (this->y != vector.y);
	}
	bool operator!=(const V2& vector) {
		return (this->x != vector.x) && (this->y != vector.y);
	}
	
};

// Multiple definition?
/*
 * make it inline to work
V2 v2i(float n) // V2 Initialize.
{
	return V2(n, n);
}*/

struct V4
{
	float x, y, width, height;
	
	V4() {}
	V4(float x, float y, float width, float height): x(x), y(y), width(width), height(height) {}
	
	V4& operator=(const V4& v)
	{
		if (this == &v)
			return *this;
		
		this->x = v.x;
		this->y = v.y;
		this->width = v.width;
		this->height = v.height;
		
		return *this;
	}
};

enum class ID_TYPE
{
    BUTTON,
    SLIDER,
    CHECK_BOX,
    Object
};

struct ID
{
    static int current_ID;

    int id;
    ID_TYPE type;
    ID(){};
    ID(ID_TYPE type): type(type)
    {
        id = current_ID;
        current_ID += 1;
    }

    ID& operator=(const ID& n_ID)
    {
        id = n_ID.id;
        type = n_ID.type;
        return *this;
    }
};
// TODO: code is mess 
// maybe need to make an cpp file to initiliaze the current_ID, for now i initiliaze it on the main function
//int ID::current_ID = 0;


#endif // SLIDER Hpp

