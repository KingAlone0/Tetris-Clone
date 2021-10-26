#include "game.hpp"
#include <iostream>

#define TILE 16

void Tetris(sf::RenderWindow& window)
{
	bool start = true;
	sf::Font font;
	font.loadFromFile("../textures/SourceCode.ttf");
	
	short int Score = 0;
	//Tetromino tetromino(getRandomTetromino(), sf::Vector2f(15 * TILE, TILE));
	Tetromino tetromino(TilesType::I, sf::Vector2f(15 * TILE, TILE));
	
	std::array<Mino, 56> Playfield;
	
	setGrid(Playfield);
	std::vector<Mino> gridSize;
	
	unsigned short int sizeOfGrid = 0;
	
	for (size_t i = 0; i < Playfield.size(); ++i)
	{
		gridSize.push_back(Playfield[i]);
	}
	
	std::vector<Tetromino*> tetrominos;
	
	while (start == true)
	{
		tetrominos.push_back(&tetromino);
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			start = false;
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)) {
			tetromino = Tetromino(TilesType::L, sf::Vector2f(15 * TILE, TILE));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
			tetromino = Tetromino(TilesType::J, sf::Vector2f(15 * TILE, TILE));
		}
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		
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
			
			tetromino = Tetromino(getRandomTetromino(), sf::Vector2f(15 * TILE, TILE));
			//tetromino = Tetromino(TilesType::T, sf::Vector2f(18 * TILE, TILE));
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
				short int rows = 0;
				for (int h = 0; h < 24; h++)
				{
					if (isFullRowAt(gridSize, h * TILE))
					{
						rows++;
						deleteRowAt(gridSize, h * TILE);
					}
				}
				if (rows != 0) {
					sf::Clock c;
					sf::Time t = c. getElapsedTime();
					Score += scoreMultiplier(rows);
					std::cout << c.getElapsedTime().asMicroseconds() << std::endl;
				}
			}
			
		}
		// --------------- Score
		sf::Text Scr(std::to_string(Score), font);
		Scr.setFillColor(sf::Color::White);
		Scr.setCharacterSize(30);
		Scr.setStyle(sf::Text::Bold);
		
		
		window.draw(Scr);
		// --------------- ^Score
		window.display();
		window.clear();
		
		//gridSize.clear(); //Clear the Vector all "frames"
		tetrominos.clear(); // Clear the vector of minos.
		
	}
	
}



short int scoreMultiplier(short int row);


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


short int scoreMultiplier(short int row)
{
	short int scr;
	switch(row)
	{
		case 1:
		scr = 40;
		break;
		case 2:
		scr = 100;
		break;
		case 3:
		scr = 300;
		break;
		case 4:
		scr = 1200;
		break;
	}
	return scr;
}