#include "mino.hpp"

#include <iostream>

Mino::Mino()
{
	sprPlace.left = 0;
    sprPlace.top = 0;
    sprPlace.width = 16;
    sprPlace.height = 16;
    
    texture.loadFromFile("../textures/textures_mino.png");
    spr.setTexture(texture);
	
    spr.setPosition(sf::Vector2f(0.f, 0.f));
	updateCollision();
}

Mino::Mino(TilesType Type) : Type(Type)
{   
    sprPlace.left = 0;
    sprPlace.top = 0;
    sprPlace.width = 16;
    sprPlace.height = 16;
    
    texture.loadFromFile("../textures/textures_mino.png");
    spr.setTexture(texture);
    
    setRect();
    spr.setTextureRect(sprPlace);
    spr.setPosition(193, 32);
    updateCollision();
}

Mino::Mino(TilesType Type, sf::Vector2f pos) : Type(Type)
{
    sprPlace.left = 0;
    sprPlace.top = 0;
    sprPlace.width = 16;
    sprPlace.height = 16;
    
    texture.loadFromFile("../textures/textures_mino.png");
    spr.setTexture(texture);
    
    setRect();
    spr.setTextureRect(sprPlace);
    spr.setPosition(pos);
    updateCollision();
	
}

void Mino::setMinoType(TilesType nType)
{
    Type = nType;
    setRect();
    spr.setTextureRect(sprPlace);
}

void Mino::setRect()
{
    switch (Type)
    {
        case TilesType::I:
        sprPlace.left = 0;
        sprPlace.top = 0;
        break;
        case TilesType::O:
        sprPlace.left = 16;
        sprPlace.top = 0;
        break;
        case TilesType::T:
        sprPlace.left = 32;
        sprPlace.top = 0;
        break;
        case TilesType::J:
        sprPlace.left = 48;
        sprPlace.top = 0;
        break;
        case TilesType::L:
        sprPlace.top = 16;
        break;
        case TilesType::S:
        sprPlace.left = 16;
        sprPlace.top = 16;
        break;
        case TilesType::Z:
        sprPlace.left = 32;
        sprPlace.top = 16;
        break;
        case TilesType::Grid:
        sprPlace.left = 48;
        sprPlace.top = 16;
        break;
    }
}

void Mino::setPosition(sf::Vector2f newPosition)
{
    spr.setPosition(newPosition);
}

void Mino::setPosition(float x, float y)
{
    spr.setPosition(x, y);
	updateCollision();
}


void Mino::updateCollision()
{
    Collision.updateCollision((unsigned)spr.getPosition().x, (unsigned)spr.getPosition().y, (unsigned)spr.getGlobalBounds().width, (unsigned)spr.getGlobalBounds().height);
}

bool Mino::canMove(BoxCollision box)
{
    if (Collision.checkBoxCollision(box))
    {
        return false;
    }
    return true;
}

void Mino::handleMovement(sf::Vector2f direction)
{
    //sf::Vector2f movement = i == 0 ? sf::Vector2f(-16.0f, 0.0f) : sf::Vector2f(16.0f, 0.0f);
    spr.move(direction);
    updateCollision();
}



bool Mino::canMove(std::vector<Mino> Minos)
{
    for (size_t i = 0; i < Minos.size(); ++i)
    {
		if (Collision.checkBoxCollision(Minos[i].Collision)){
            return false;
        }
    }
    return true;
}


void Mino::setIndex(short int i, short int x, short int y)
{
    index = i;
    position_index.x = x;
    position_index.y = y;
}

void Mino::updateIndex(unsigned char nIndex)
{
	int x = 0, y = 0;
	
    rotatedPosition.x = x;
    rotatedPosition.y = y;
	tIndex = nIndex;
    //index = position_index.y * 3 + position_index.x;
}


unsigned char Mino::updateIndexPosition(short int degree)
{
	unsigned char nIndex;
    if (degree == 0) 
    {
        nIndex = position_index.y * 3 + position_index.x;
    }
    if (degree == 1)
    {
        nIndex = 6 + position_index.y - (3 * position_index.x);
    }
    if(degree == 2)
    {
        nIndex = 8 - (position_index.y * 3) - position_index.x;
    }
    if (degree == 3)
    {
        nIndex = 2 - position_index.y + (position_index.x * 3);
    }
	
	return nIndex;
	//updateIndex(nIndex);
}
