#pragma once

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
