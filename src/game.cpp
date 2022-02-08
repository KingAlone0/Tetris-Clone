#include "game.hpp"
#include <iostream>
#include <vector>
#include <numeric>

#define TILE 16

void Tetris(RenderWindow& window)
{
	sf::Texture bg;
	bg.loadFromFile("../textures/playfield_background.png");
	sf::Sprite backGround;
	backGround.setTexture(bg);
	backGround.setPosition(0.f, 0.f);
	
	bool start = true;
	sf::Font font;
	font.loadFromFile("../textures/SourceCode.ttf");
	sf::Texture texture;
	texture.loadFromFile("../textures/textures_mino.png");
	texture.setRepeated(true);
	
	short int Score = 0;
	Tetromino te(getRandomTetromino(), sf::Vector2f(20 * TILE, TILE));
	Tetromino tetromino(TilesType::I, sf::Vector2f(15 * TILE, TILE));
	
	
	std::vector<Mino> minos_grid;
	unsigned short int size_of_grid = 0;
	
	Keyboard k;
	
	Tetromino holded_tetromino;
	Tetromino next_tetromino(getRandomTetromino(), sf::Vector2f(5 * TILE, TILE), false, true);
	while (start == true)
	{
        window.draw(backGround);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			start = false;
			break;
		}
		if (k.justPressed(sf::Keyboard::Key::C)) {
			holdTetromino(tetromino, holded_tetromino, next_tetromino);
		}
		

        { // Debug
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) {
                tetromino = Tetromino(TilesType::I, sf::Vector2f(15 * TILE, TILE));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) {
                tetromino = Tetromino(TilesType::O, sf::Vector2f(15 * TILE, TILE));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) {
                tetromino = Tetromino(TilesType::T, sf::Vector2f(15 * TILE, TILE));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4)) {
                tetromino = Tetromino(TilesType::J, sf::Vector2f(15 * TILE, TILE));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5)) {
                tetromino = Tetromino(TilesType::L, sf::Vector2f(15 * TILE, TILE));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num6)) {
                tetromino = Tetromino(TilesType::Z, sf::Vector2f(15 * TILE, TILE));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num7)) {
                tetromino = Tetromino(TilesType::S, sf::Vector2f(15 * TILE, TILE));
            }
        }


		sf::Event event;
		while (window.window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
                SoundTrack::stopOST();
				window.window.close();
			}
		}
		
		tetromino.Update(&window, minos_grid);
		
		if (holded_tetromino.isValid()) 
			holded_tetromino.Update(&window, minos_grid);
		if (next_tetromino.isValid())
			next_tetromino.Update(&window, minos_grid);
		
		
		if (tetromino.isOnFloor()) {
			for (size_t i = 0; i < 4; ++i)
			{
				Mino n_mino = tetromino.getMino()[i];
				minos_grid.push_back(n_mino);
			}
			nextTetromino(tetromino, next_tetromino);
		}
        if (!tetromino.canMove(minos_grid))
        {
            // TODO: Make the game over window, maybe other screen, or something who will be in front of everihing. 
            return;
        }
		
		for (size_t i = 0; i < minos_grid.size(); ++i)
		{
			window.draw(minos_grid[i].getSprite());
		}
		
		if (size_of_grid < minos_grid.size())
		{
			short int rows = 0;
			
			for (int h = 0; h < 24; h++)
			{
				if (isRowFullAt(minos_grid, h * TILE))
				{
					deleteRowAt(minos_grid, h * TILE);
					rows++;
				}
			}
			if (rows != 0) {
				Score += scoreMultiplier(rows);
			}
			size_of_grid = minos_grid.size();
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
	}
	
}

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

void deleteRowAt(std::vector<Mino>& grid, unsigned short int h) // Delete a line.
{
	// NOTE(AloneTheKing): Could use iteretors here instead of use --i, Clean Code?
	for (size_t i = 0; i < grid.size(); ++i)
	{ 
		if (grid[i].getPosition().y == h)
		{
			grid.erase(grid.cbegin() + i);
			i--;
		}
	}
	for (size_t i = 0; i < grid.size(); ++i) // Move the minos down for after delete a line.
	{
		if (grid[i].getPosition().y < h)
		{
			grid[i].setPosition(sf::Vector2f(grid[i].getPosition().x, grid[i].getPosition().y + TILE));
		}
	}
}

bool isRowFullAt(const std::vector<Mino>& grid, unsigned short int h)
{
	int p = 0;
	for (size_t i = 0; i < grid.size(); ++i)
	{ 
		if (grid[i].getPosition().y == h)
		{
			p++;
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

void holdTetromino(Tetromino& tetromino, Tetromino& holded_tetromino, Tetromino& next_tetromino)
{
	Tetromino temp_tetromino = tetromino;
	if (holded_tetromino.is_holded) {
		tetromino = holded_tetromino;
		tetromino.setPosition(sf::Vector2f(15 * TILE, TILE));
		tetromino.is_holded = false;
		tetromino.is_playable = true;
	}
	else if (next_tetromino.isValid()){
		nextTetromino(tetromino, next_tetromino);
	}
	
	holded_tetromino = temp_tetromino;
	holded_tetromino.is_playable = false;
	holded_tetromino.is_holded = true;
	holded_tetromino.setPosition(sf::Vector2f(24 * TILE, TILE));
}

void nextTetromino(Tetromino& tetromino, Tetromino& next_tetromino)
{
	tetromino = next_tetromino;
	tetromino.setPosition(sf::Vector2f(10 * TILE, TILE));
	tetromino.is_holded = false;
	tetromino.is_playable = true;
	
	next_tetromino = Tetromino(getRandomTetromino(), sf::Vector2f(5 * TILE, TILE), false, true);
	next_tetromino.is_playable = false;
	next_tetromino.is_holded = true;
}

