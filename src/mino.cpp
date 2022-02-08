#include "mino.hpp"

#include <iostream>

Mino::Mino()
{
	sprPlace.left = 0;
    sprPlace.top = 0;
    sprPlace.width = 16;
    sprPlace.height = 16;
    
    texture = Defaults::Get().MinoTexture();
    spr.setTexture(texture);
	
    spr.setPosition(sf::Vector2f(0.f, 0.f));
	updateCollision();
	Collision.addAreaPlayable(176.f, 0.f, 182.f, 384.f);
}

Mino::Mino(TilesType Type) : Type(Type)
{   
    sprPlace.left = 0;
    sprPlace.top = 0;
    sprPlace.width = 16;
    sprPlace.height = 16;
    
    texture = Defaults::Get().MinoTexture();
    spr.setTexture(texture);
    
    setRect();
    spr.setTextureRect(sprPlace);
    spr.setPosition(193, 32);
    updateCollision();
	Collision.addAreaPlayable(176.f, 0.f, 182.f, 384.f);
}

Mino::Mino(TilesType Type, sf::Vector2f pos) : Type(Type)
{
    sprPlace.left = 0;
    sprPlace.top = 0;
    sprPlace.width = 16;
    sprPlace.height = 16;
    
    texture = Defaults::Get().MinoTexture();
    spr.setTexture(texture);
    
    setRect();
    spr.setTextureRect(sprPlace);
    spr.setPosition(pos);
    updateCollision();
	Collision.addAreaPlayable(176.f, 0.f, 182.f, 384.f);
	
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
		sprPlace.left = 0;
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
	updateCollision();
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


bool Mino::canMove(std::vector<Mino>& minos)
{
	if (minos.size() == NULL && Collision.checkLimitCollision()) {
		return false;
	}
	else
	{
		for (size_t i = 0; i < minos.size(); ++i)
		{
			if (Collision.checkBoxCollision(minos[i].Collision)){
				return false;
			}
		}
	}
    return true;
}


void Mino::handleMovement(sf::Vector2f direction)
{
    spr.move(direction);
    updateCollision();
}

void Mino::handleMovement(V2 direction)
{
	sf::Vector2f m(direction.x, direction.y);
    spr.move(m);
    updateCollision();
}

void Mino::moveDown()
{
	spr.move(sf::Vector2f(0.f, 16.f));
	updateCollision();
}

void Mino::setIndex(unsigned short int i, unsigned short int based)
{
	index.i = i;
	index.based = based;
	index.updateCoordinates();
	// NOTE(AloneTheKing): index = Index(i, based) ? maybe?
	rIndex.i = i;
	rIndex.based = based;
	index.updateCoordinates();
	tIndex = i;
}

void Mino::updateIndex(unsigned char nIndex)
{
	int x = 0, y = 0;
	
    rotatedPosition.x = x;
    rotatedPosition.y = y;
	tIndex = nIndex;
    //index = position_index.y * 3 + position_index.x;
}


Index Mino::updateIndexPosition(short int degree)
{
	rIndex.i = tIndex;
	rIndex.updateCoordinates();
	unsigned short int indexs[3];
	if (index.based == 4)
	{
		indexs[0] = 12;
		indexs[1] = 15;
		indexs[2] = 3;
	}
	else if (index.based == 3)
	{
		indexs[0] = 6;
		indexs[1] = 8;
		indexs[2] = 2;
	}
	
    if (degree == 0) 
    {
		tIndex = index.y * index.based + index.x;
    }
    if (degree == 1)
    {
		tIndex = indexs[0] + index.y - (index.based * index.x);
    }
    if(degree == 2)
    {
		tIndex = indexs[1] - (index.y * index.based) - index.x;
    }
    if (degree == 3)
    {
		tIndex = indexs[2] - index.y + (index.x * index.based);
    }
	Index n_Index(tIndex);
	
	return rIndex;
	//updateIndex(nIndex);
}

void Mino::Update(RenderWindow* window)
{
	window->draw(spr);
}

Mino& Mino::operator=(const Mino& mino)
{
	this->Type = mino.Type;
	
	sf::Vector2f position = mino.spr.getPosition();
	
	setRect();
	spr.setTextureRect(sprPlace);
	spr.setPosition(position);
	updateCollision();
}
