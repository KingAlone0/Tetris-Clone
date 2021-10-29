#pragma once
#include <SFML/Graphics.hpp>
#include "mino.hpp"
#include "keyboard.hpp"

#include <iostream>
#include <array>

class Tetromino
{
    private:
    //std::vector<Mino> mino;
	Mino mino[4];
    TilesType Type;
    short int nRotation = 0; // NOTE(AloneTheKing): Firt rotation never works don't fucking know why.
	Keyboard keyboard;
	bool on_floor = false;
	
	sf::Vector2f tPos;
	
    public:
    Tetromino(TilesType Type);
    Tetromino(TilesType Type, sf::Vector2f Position);
    Tetromino(const Tetromino& tetromino);
    
    void setPosition(sf::Vector2f newPosition);
    std::vector<sf::FloatRect> getMinosBounds();
	
    bool isOnFloor() const { return on_floor; }
	
    void handleMovement(Directions d, std::vector<Mino>& Minos, bool Collided = false); // d = direction
    bool canMove(std::vector<Mino>& Minos);
	void checkInput(const std::vector<Tetromino*>& t); //__DELETE__
	void checkInput(std::vector<Mino>& t);
	
	//std::vector<Mino> getMino() const { return mino; }
	Mino* getMino() { return mino; }
	
    //-------- Rotate Tetromino
    void rotateTetromino(std::vector<Mino>& minos);
	
	//-------- Update
	void Update(std::vector<Mino>& Minos);
    void updateMinoPosition(sf::RenderWindow *window);
	
    
    private:
    void updateRotationPosition();
    void setTetrominoGeometry();
	void setMinoType();
	void hardDrop(std::vector<Mino>& minos);
	void wallKick(std::vector<Mino>& minos);
	
	//----------
	public:
	Tetromino& operator=(const Tetromino& t);
	//----------
};