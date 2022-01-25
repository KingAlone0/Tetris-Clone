#pragma once
#include <SFML/Graphics.hpp>
#include "mino.hpp"
#include "sound.hpp"
#include "keyboard.hpp"
#include <thread>

#include <iostream>
#include <array>

class Tetromino
{
    private:
    //std::vector<Mino> mino;
	Mino shadow[4];
	Mino mino[4];
    TilesType Type = TilesType::None;
    short int nRotation = 0; 
	Keyboard keyboard;
	sf::Vector2f tPos;
	bool on_floor = false;
    sf::Clock timer;
    sf::Clock clock;
    struct {
        sf::Time rotation;
        sf::Time move;
        sf::Time hardDrop;
    } timers;
	
	public:
	bool is_playable;
	bool is_holded = false;
	
    public:
	Tetromino() { is_playable = false; }
    Tetromino(TilesType Type);
    Tetromino(TilesType Type, sf::Vector2f Position, bool is_playable = true, bool is_holded = false);
    Tetromino(const Tetromino& tetromino);
    
    void setPosition(sf::Vector2f newPosition);
    std::vector<sf::FloatRect> getMinosBounds();
	
    bool isOnFloor() const { return on_floor; }
	
    void handleMovement(Directions d, std::vector<Mino>& Minos, bool Collided = false); 
    bool canMove(std::vector<Mino>& Minos);
	void checkInput(std::vector<Mino>& t);
	
	Mino* getMino() { return mino; }
	
    //-------- Rotate Tetromino
    void rotateTetromino(std::vector<Mino>& minos);
	
	//-------- Update
    void Update(RenderWindow* window, std::vector<Mino>& Minos);
	
	bool isValid() { return (Type != TilesType::None); }
    
    private:
    void updateRotationPosition();
    void setTetrominoGeometry();
	void setMinoType();
	void hardDrop(std::vector<Mino>& minos);
	void wallKick(std::vector<Mino>& minos);
	void setShadow();
	void setShadowPosition(std::vector<Mino>& grid);
	
	//----------
	public:
	Tetromino& operator=(const Tetromino& t);
	//----------
};
