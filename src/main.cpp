#include <SFML/Graphics.hpp>
#include <iostream>

#include "tetromino.hpp"
#include "renderWindow.hpp"

#include <ctime>
#include <random>

#define TILE 16

TilesType getRandomTetromino()
{
	std::mt19937 mersenne { static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::uniform_int_distribution<> n {0, 6};
	unsigned short int t = n(mersenne);
	TilesType type;
	switch(t)
	{
		case 0:
		type = TilesType::I;
		break;
		case 1:
		type = TilesType::J;
		break;
		case 2:
		type = TilesType::L;
		break;
		case 3:
		type = TilesType::O;
		break;
		case 4:
		type = TilesType::S;
		break;
		case 5:
		type = TilesType::T;
		case 6:
		type = TilesType::Z;
		break;
	}
	return type;
}

void deleteRowAt(std::vector<Mino>& grid, int h) // Delete a line.
{
	for (size_t i = 0; i < grid.size(); ++i)
	{
		if (grid[i].getPosition().y == h)
		{
			if (grid[i].getPosition().x != 11 * TILE && grid[i].getPosition().x != 22 * TILE) {
				grid.erase(grid.cbegin() + i);
				i--;
			}
		}
	}
	for (size_t i = 0; i < grid.size(); ++i) // Move the minos down for after delete a line.
	{
		if (grid[i].getPosition().y < h)
		{
			if (grid[i].getPosition().x != 11 * TILE && grid[i].getPosition().x != 22 * TILE) {
				grid[i].setPosition(sf::Vector2f(grid[i].getPosition().x, grid[i].getPosition().y + TILE));
			}
		}
	}
}

// TODO(AloneTheKing): Need to make the score system, and make it show at screen
bool isFullRowAt(const std::vector<Mino>& grid, unsigned short int h)
{
	int p = 0;
	for (size_t i = 0; i <= grid.size(); ++i)
	{ 
		if (grid[i].getPosition().y == h)
		{
			if (grid[i].getPosition().x != 11 * TILE && grid[i].getPosition().x != 22 * TILE) {
				p++;
			}
		}
	}
	return p >= 10 ? true : false;
}
//Grid 12 x 22

void setGrid(std::array<Mino, 56>& g)
{
	int i = 0;
	for (int x = 11; x < 23; ++x) {
		for (int y = 2; y < 25; ++y) {
			if (x == 11 || x == 22 || y == 24)
			{
				if (g[i].getPosition().x == 0.f && g[i].getPosition().x != x)
				{
					g[i].setMinoType(TilesType::Grid);
					g[i].setPosition(x * TILE, y * TILE);
					i++;
				}
			}
		}
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(36 *TILE , 26 * TILE), "Mandioca");
	Keyboard k;
	
	
	Tetromino tetromino(TilesType::I, sf::Vector2f(18 * TILE, TILE));
	Tetromino tTmino(TilesType::I, sf::Vector2f(18 * TILE, 13 * TILE)); // Mino for test.
	
	// ---------
	std::array<Mino, 56> Playfield;
	//Mino Playfield[56];
	
	setGrid(Playfield);
	// ---------
	std::vector<Mino> gridSize;
	unsigned short int sizeOfGrid = 0;
	
	for (size_t i = 0; i < Playfield.size(); ++i)
	{
		gridSize.push_back(Playfield[i]);
	}
	
	std::vector<Tetromino*> tetrominos;
	window.setFramerateLimit(60);
	while(window.isOpen())
	{
		
		tetrominos.push_back(&tTmino);
		tetrominos.push_back(&tetromino);
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
			window.clear();
			return EXIT_SUCCESS;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)) {
			tetromino = Tetromino(TilesType::L, sf::Vector2f(18 * TILE, TILE));
		}
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		
		///////////////////////////////////
		//tetromino.checkInput(tetrominos);
		//tetromino.checkInput(gridSize);
		///////////////////////////////////
		tetromino.Update(gridSize);
		for (size_t i = 0; i < tetrominos.size(); ++i) // __DELETE__
		{
			tetrominos[i]->updateMinoPosition(&window);
		}
		
		for (int i = 0; i < 56; ++i)
		{
			window.draw(Playfield[i].getSprite());
		}
		
		if (tetromino.isOnFloor()) {
			for (size_t i = 0; i < tetromino.getMino().size(); ++i)
			{
				gridSize.push_back(tetromino.getMino()[i]);
			}
			
			tetromino = Tetromino(getRandomTetromino(), sf::Vector2f(18 * TILE, TILE));
			tetrominos.clear();
		}
		//std::cout << gridSize.size() << std::endl;
		
		for (size_t i = 0; i < gridSize.size(); ++i)
		{
			window.draw(gridSize[i].getSprite());
		}
		
		if (sizeOfGrid != (int)gridSize.size())
		{
			sizeOfGrid = gridSize.size();
			if (sizeOfGrid != 0)
			{
				for (int h = 0; h < 24; h++)
				{
					if (isFullRowAt(gridSize, h * TILE))
					{
						deleteRowAt(gridSize, h * TILE);
					}
				}
			}
			
		}
		
		window.display();
		window.clear();
		
		//gridSize.clear(); //Clear the Vector all "frames"
		tetrominos.clear(); // Clear the vector of minos.
	}
	
	
	return EXIT_SUCCESS;
}
