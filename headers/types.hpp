#pragma once
#include <SFML/Graphics.hpp>

enum TilesType
{
    I,
    J,
    L,
    O,
    S,
    T,
    Z,
    Grid
};

enum class Directions
{
	Left = 0,
	Right = 1,
	Down = 2,
	Up = 3, // Debbug purpose only. __DELETE__
	None = 9
};


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
	V2& operator*(short int mp)
	{
		this->x = x * mp;
		this->y = y * mp;
		
		return *this;
	}
	
	bool operator==(const sf::Vector2f vector)
	{
		return (this->x == vector.x) && (this->y == vector.y);
	}
	
	bool operator!=(const sf::Vector2f vector)
	{
		return (this->x != vector.x) && (this->y != vector.y);
	}
	
	bool operator!=(const V2& vector)
	{
		return (this->x != vector.x) && (this->y != vector.y);
	}
	
};

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
