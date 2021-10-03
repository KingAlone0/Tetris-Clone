#pragma once
#include <SFML/Graphics.hpp>
#include "mino.hpp"
#include "keyboard.hpp"

#include <iostream>
#include <array>

class Tetromino
{
    private:
    std::vector<Mino> mino;
    TilesType Type;
    short int nRotation = 0;
	Keyboard keyboard;
	
	
	
	// ------------Working*
	//Mino test[4];
	//std::array<Mino, 4> test;
	// ------------
    
    public:
    Tetromino(TilesType Type);
    Tetromino(TilesType Type, sf::Vector2f Position);
    
    void updateMinoPosition(sf::RenderWindow *window);
    void setPosition(sf::Vector2f newPosition);
    void setEachMinoPosition(); // Private?
    std::vector<sf::FloatRect> getMinosBounds();
    
    void handleMovement(Directions d, std::vector<Mino> Minos); // d = direction
    bool canMove(const std::vector<Mino>& Minos);
	void checkInput(std::vector<Tetromino*> t); // NOTE(AloneTheKing): Pass as reference to not make a copy maybe.
	void checkInput(const std::vector<Mino>& t); // NOTE(AloneTheKing): Pass as reference to not make a copy maybe.
	
	
    //-------- Rotate Tetromino
    void rotateTetromino();
	
	//-------- Update
	void Update(const std::vector<Mino>& Minos);
	
    
    private:
    void updateRotationPosition();
    void setTetrominoGeometry();
	
};