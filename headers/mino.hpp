#pragma once
#include <SFML/Graphics.hpp>
#include "types.hpp"
#include "collision.hpp"
#include <iostream>



class Mino
{
    private:
    sf::Texture texture;
    sf::Sprite spr;
    TilesType Type;
    sf::IntRect sprPlace;
	Index index;
	Index rIndex;
	unsigned char tIndex;
    sf::Vector2i position_index;
	sf::Vector2i rotatedPosition;
	
	public:
    BoxCollision Collision;
	
    
    
    
    /*  Set the position of the mino tile on the texture. */
    void setRect();
    void setMinoPosition();
    bool canMove(BoxCollision box);
    
    public:
    Mino();
    Mino(TilesType Type);
    Mino(TilesType Type, sf::Vector2f pos);
	
	sf::Vector2f getPosition() const { return spr.getPosition(); }
    
    
    sf::Sprite getSprite() const { return spr; }
	
    void setMinoType(TilesType nType);
    void setSpriteLocation(sf::Vector2f pos) { spr.setPosition(pos); }
	void handleMovement(sf::Vector2f direction); // if 0 move left, if 1 move right
    void setPosition(sf::Vector2f newPosition);
    void setPosition(float x, float y);
    bool canMove(std::vector<Mino> Minos); // Could use a static vector of Mino and at the construction add a mino to it
    void updateCollision();
    
    void setIndex(uint8_t i);
	Index getIndex() const { return index; }
	Index getRotatedIndex() const { return rIndex; }
	Index updateIndexPosition(short int degree);
	unsigned char getIndexRotation() const { return tIndex; }
	void moveDown();
    
    // void testIndexUpdate();
    private:
    void updateIndex(unsigned char nIndex);
	// NOTE(AloneTheKing): Need to debug the rotation to know what tha fuck is going wrong
    
    
};

//||||||||||||||||||||||||||||||||||||
// 0 1 2 || 6 3 0 || 8 7 6 || 2 5 6 || 
// 3 4 5 || 7 4 1 || 5 4 3 || 1 4 7 ||
// 6 7 8 || 8 5 2 || 2 1 0 || 0 3 8 ||
//   0   ||   1   ||   2   ||   3   ||
//||||||||||||||||||||||||||||||||||||
