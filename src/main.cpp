#include <SFML/Graphics.hpp>
#include <iostream>

#include "tetromino.hpp"
#include "renderWindow.hpp"


#define TILE 16

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
	
    
    
    Tetromino tetromino(TilesType::S, sf::Vector2f(18 * TILE, TILE)); // Creates a Tetromino of type Square.
    Tetromino tTmino(TilesType::I, sf::Vector2f(18 * TILE, 13 * TILE)); // Mino for test.
	
	// ---------
	std::array<Mino, 56> Playfield;
	//Mino Playfield[56];
	
	setGrid(Playfield);
	// ---------
    std::vector<Mino> gridSize;
	
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
		tetromino.Update(gridSize);
		///////////////////////////////////
		
		for (size_t i = 0; i < tetrominos.size(); ++i)
		{
			tetrominos[i]->updateMinoPosition(&window);
		}
		
		for (int i = 0; i < 56; ++i)
		{
			window.draw(Playfield[i].getSprite());
		}
		
		
		window.display();
		window.clear();
		
		//gridSize.clear(); //Clear the Vector all "frames"
		tetrominos.clear(); // Clear the vector of minos.
    }
    
    
    return EXIT_SUCCESS;
}
