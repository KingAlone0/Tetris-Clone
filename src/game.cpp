#include "game.hpp"
#include <iostream>

#define TILE 16

void Tetris(sf::RenderWindow& window)
{
	bool start = true;
	sf::Font font;
	font.loadFromFile("../textures/SourceCode.ttf");
	sf::Texture texture;
	texture.loadFromFile("../textures/textures_mino.png");
	texture.setRepeated(true);
	
	short int Score = 0;
	Tetromino te(getRandomTetromino(), sf::Vector2f(20 * TILE, TILE));
	Tetromino tetromino(TilesType::I, sf::Vector2f(15 * TILE, TILE));
	
	std::array<sf::Sprite, 56> Playfield;
	for (size_t i = 0; i < Playfield.size(); ++i)
	{
		Playfield[i].setTexture(texture);
		Playfield[i].setTextureRect(sf::Rect<int>(48, 16, 16, 16));
		Playfield[i].setPosition(0.f, 0.f);
	}
	setGrid(Playfield);
	
	
	std::vector<Mino> minos_grid;
	unsigned short int sizeOfGrid = 0;
	
	std::vector<Tetromino*> tetrominos;
	
	while (start == true)
	{
		for (size_t i = 0; i < Playfield.size(); ++i) {
			window.draw(Playfield[i]);
		}
		tetrominos.push_back(&tetromino);
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			start = false;
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)) {
			tetromino = Tetromino(TilesType::S, sf::Vector2f(15 * TILE, TILE));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
			tetromino = Tetromino(TilesType::Z, sf::Vector2f(15 * TILE, TILE));
		}
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		
		tetromino.Update(minos_grid);
		tetromino.updateMinoPosition(&window);
		
		if (tetromino.isOnFloor()) {
			for (size_t i = 0; i < 4; ++i)
			{
				minos_grid.push_back(tetromino.getMino()[i]);
			}
			
			tetromino = Tetromino(getRandomTetromino(), sf::Vector2f(15 * TILE, TILE));
			//tetromino = Tetromino(TilesType::T, sf::Vector2f(18 * TILE, TILE));
			tetrominos.clear();
		}
		
		for (size_t i = 0; i < minos_grid.size(); ++i)
		{
			window.draw(minos_grid[i].getSprite());
		}
		
		if (sizeOfGrid != (int)minos_grid.size())
		{
			sizeOfGrid = minos_grid.size();
			if (sizeOfGrid != 0)
			{
				short int rows = 0;
				for (int h = 0; h < 24; h++)
				{
					if (isFullRowAt(minos_grid, h * TILE))
					{
						rows++;
						deleteRowAt(minos_grid, h * TILE);
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
void setGrid(std::array<sf::Sprite, 56>& g)
{
	int i = 0;
	for (int x = 11; x < 23; ++x) {
		for (int y = 2; y < 25; ++y) {
			if (x == 11 || x == 22 || y == 24)
			{
				if (g[i].getPosition().x == 0.f && g[i].getPosition().x != x)
				{
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