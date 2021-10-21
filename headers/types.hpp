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
			switch(i)
			{
				case 0:
				x = 0;
				y = 0;
				break;
				case 1:
				x = 1;
				y = 0;
				break;
				case 2:
				x = 2;
				y = 0;
				break;
				case 3:
				x = 3;
				y = 0;
				break;
				case 4:
				x = 0;
				y = 1;
				break;
				case 5:
				x = 1;
				y = 1;
				break;
				case 6:
				x = 2;
				y = 1;
				break;
				case 7:
				x = 3;
				y = 1;
				break;
				case 8:
				x = 0;
				y = 2;
				break;
				case 9:
				x = 1;
				y = 2;
				break;
				case 10:
				x = 2;
				y = 2;
				break;
				case 11:
				x = 3;
				y = 2;
				break;
				case 12:
				x = 0;
				y = 3;
				break;
				case 13:
				x = 1;
				y = 3;
				break;
				case 14:
				x = 2;
				y = 3;
				break;
				case 15:
				x = 3;
				y = 3;
				break;
			}
		}
		else if (based == 3)
		{
			switch(i)
			{
				case 0:
				x = 0;
				y = 0;
				break;
				case 1:
				x = 1;
				y = 0;
				break;
				case 2:
				x = 2;
				y = 0;
				break;
				case 3:
				x = 0;
				y = 1;
				break;
				case 4:
				x = 1;
				y = 1;
				break;
				case 5:
				x = 2;
				y = 1;
				break;
				case 6:
				x = 0;
				y = 2;
				break;
				case 7:
				x = 1;
				y = 2;
				break;
				case 8:
				x = 2;
				y = 2;
				break;
			}
		}
	}
};
