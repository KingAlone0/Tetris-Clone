#include "tetromino.hpp"

#define TILE 16

Tetromino::Tetromino(TilesType Type): Type(Type)
{
    setMinoType();
    setTetrominoGeometry();
}
Tetromino::Tetromino(const Tetromino& tetromino)
{
	Type = tetromino.Type;
    setMinoType();
    setTetrominoGeometry();
    setPosition(tPos);
}

Tetromino::Tetromino(TilesType Type, sf::Vector2f Position): Type(Type), tPos(Position)
{
    setMinoType();
    setTetrominoGeometry();
    setPosition(tPos);
}

void Tetromino::setMinoType()
{
	if (Type != TilesType::Grid)
    {
        Mino* tMino;
		for (int x = 0; x < 4; x++)
		{
			tMino = new Mino(Type);
			mino.push_back(*tMino);
		}
		
    }
}

void Tetromino::setTetrominoGeometry()
{
    switch (Type)
    {
        case TilesType::I:
        mino[0].setSpriteLocation(sf::Vector2f(0.f , 0.f));
        mino[0].setIndex(0, 0, 0);
        mino[1].setSpriteLocation(sf::Vector2f(16.f, 0.f));
        mino[1].setIndex(1, 0, 1);
        mino[2].setSpriteLocation(sf::Vector2f(32.f, 0.f));
        mino[2].setIndex(2, 0, 2);
        mino[3].setSpriteLocation(sf::Vector2f(48.f, 0.f));
        mino[3].setIndex(3, 0, 3);
        break;
        case TilesType::O:
        mino[0].setSpriteLocation(sf::Vector2f(0.f, 0.f));
        mino[0].setIndex(0, 0, 0);
        mino[1].setSpriteLocation(sf::Vector2f(16.f, 0.f));
        mino[1].setIndex(1, 0, 1);
        mino[2].setSpriteLocation(sf::Vector2f(0.f, 16.f));
        mino[2].setIndex(3, 1, 0);
        mino[3].setSpriteLocation(sf::Vector2f(16.f, 16.f));
        mino[3].setIndex(4, 0, 1);
        break;
        case TilesType::T:
        mino[0].setSpriteLocation(sf::Vector2f(0.f, 16.f));
        mino[0].setIndex(3, 0, 1);
        mino[1].setSpriteLocation(sf::Vector2f(16.f, 16.f));
        mino[1].setIndex(4, 1, 1);
        mino[2].setSpriteLocation(sf::Vector2f(32.f, 16.f));
        mino[2].setIndex(5, 2, 1);
        mino[3].setSpriteLocation(sf::Vector2f(16.f, 0.f));
        mino[3].setIndex(1, 1, 0);
        break;
        case TilesType::J:
        mino[0].setSpriteLocation(sf::Vector2f(0.f, 0.f));
        mino[0].setIndex(3, 0, 1);
        mino[1].setSpriteLocation(sf::Vector2f(32.f, 0.f));
        mino[1].setIndex(4, 1, 1);
        mino[2].setSpriteLocation(sf::Vector2f(16.f, 0.f));
        mino[2].setIndex(5, 2, 1);
        mino[3].setSpriteLocation(sf::Vector2f(32.f, 16.f));
        mino[3].setIndex(8, 2, 2);
        break;
        case TilesType::L:
        mino[0].setSpriteLocation(sf::Vector2f(0.f, 16.f));
        mino[0].setIndex(3, 0, 1);
        mino[1].setSpriteLocation(sf::Vector2f(32.f, 16.f));
        mino[1].setIndex(4, 1, 1);
        mino[2].setSpriteLocation(sf::Vector2f(16.f, 16.f));
        mino[2].setIndex(5, 2, 1);
        mino[3].setSpriteLocation(sf::Vector2f(32.f, 0.f));
        mino[3].setIndex(2, 2, 0);
        break;
        case TilesType::S:
        mino[0].setSpriteLocation(sf::Vector2f(16.f, 0.f));
        mino[0].setIndex(1, 0, 1);
        mino[1].setSpriteLocation(sf::Vector2f(16.f, 16.f));
        mino[1].setIndex(4, 1, 1);
        mino[2].setSpriteLocation(sf::Vector2f(0.f, 16.f));
        mino[2].setIndex(3, 1, 0);
        mino[3].setSpriteLocation(sf::Vector2f(32.f, 0.f));
        mino[3].setIndex(2, 2, 0);
        break;
        case TilesType::Z:
        mino[0].setSpriteLocation(sf::Vector2f(0.f, 0.f));
        mino[0].setIndex(0, 0, 0);
        mino[1].setSpriteLocation(sf::Vector2f(16.f, 16.f));
        mino[1].setIndex(4, 1, 1);
        mino[2].setSpriteLocation(sf::Vector2f(16.f, 0.f));
        mino[2].setIndex(1, 0, 1);
        mino[3].setSpriteLocation(sf::Vector2f(32.f, 16.f));
        mino[3].setIndex(5, 1, 2);
        break;
		case TilesType::Grid:
		break;
    }
}

void Tetromino::updateMinoPosition(sf::RenderWindow *window)
{
    for (int i = 0; i < 4; ++i){
        window->draw(mino[i].getSprite());
		mino[i].updateCollision();
    }
}

void Tetromino::setPosition(sf::Vector2f newPosition = sf::Vector2f(0.f, 0.f))
{
	for (int i = 0; i < 4; ++i) {
        mino[i].setSpriteLocation(newPosition + mino[i].getSprite().getPosition());
    }
}

void Tetromino::handleMovement(Directions d, std::vector<Mino>& Minos)
{
	sf::Vector2f direction;
	if (d == Directions::Left)
		direction = sf::Vector2f(-16.f, 0.f);
	else if (d == Directions::Right)
		direction = sf::Vector2f(16.f, 0.f);
	else if (d == Directions::Down)
		direction = sf::Vector2f(0.f, 16.f);
	else if (d == Directions::Up) // Debbug purpose only __DELETE__
		direction = sf::Vector2f(0.f, -16.f);
	
	for (int i = 0; i < 4; ++i) {
        mino[i].handleMovement(direction);
	}
	
	if (!canMove(Minos)) {
		direction = d == Directions::Left ? sf::Vector2f(16.f, 0.f) : sf::Vector2f(-16.f, 0.f);
		if (d != Directions::Left && d != Directions::Right) {
			direction = d == Directions::Down ? sf::Vector2f(0.f, -16.f) : sf::Vector2f(0.f, 16.f);
		}
		for (int i = 0; i < 4; ++i) {
			mino[i].handleMovement(direction);
		}
		//Minos.push_back(m);// NOTE(AloneTheKing): Need to delete the class now.
		//this->~Tetromino();
		
		if (d == Directions::Down) {
			onFloor = true;
		}
	}
	
}

bool Tetromino::canMove(std::vector<Mino>& Minos)
{
    //for (int i = 0; i < 4; ++i){
    for (Mino m : mino) {
        if(!m.canMove(Minos)) {
            return false;
        }
    }
    return true;
}

// ---- Rotate Tetromino
void Tetromino::rotateTetromino()
{
    if (Type == TilesType::O)
		return;
	
	
    if (nRotation < 3) {
        nRotation ++;
	}
    else if (nRotation == 3) {
        nRotation = 0;
	}
	if (Type == TilesType::Z || Type == TilesType::S)
	{
		if (nRotation > 1){
			nRotation = 0;
		}
	}
	
    updateRotationPosition();
}

void Tetromino::updateRotationPosition()
{
    sf::Vector2f pivot = mino[1].getSprite().getPosition();
    for (int i = 0; i < 4; ++i)
    {
        unsigned char index = mino[i].updateIndexPosition(nRotation);
        switch (index)
        {
            case 0:
            mino[i].setPosition(pivot.x - 16.f, pivot.y - 16.f);
            break;
            case 1:
            mino[i].setPosition(pivot.x, pivot.y - 16.f);
            break;
            case 2:
            mino[i].setPosition(pivot.x + 16.f, pivot.y - 16.f);
            break;
            case 3:
            mino[i].setPosition(pivot.x - 16.f, pivot.y);
            break;
            case 4:
            break;
            case 5:
            mino[i].setPosition(pivot.x + 16.f, pivot.y);
            break;
            case 6:
            mino[i].setPosition(pivot.x - 16.f, pivot.y + 16.f);
			break;
            case 7:
            mino[i].setPosition(pivot.x, pivot.y + 16.f);
            break;
            case 8:
            mino[i].setPosition(pivot.x + 16.f, pivot.y + 16.f);
			break;
        }
    }
}

void Tetromino::checkInput(const std::vector<Tetromino*>& t) // __DELETE__ >? 
{
	
	std::vector<Mino> m;
	for (size_t i = 0; i < t.size(); ++i) {
		if (t[i] != this) {
			for (size_t p = 0; p < t[i]->mino.size(); p++) {
				m.push_back(t[i]->mino[p]);
			}
		}
	}
	
	if (keyboard.checkInput(sf::Keyboard::Key::Left)) {
		handleMovement(Directions::Left, m);
	}
	if (keyboard.checkInput(sf::Keyboard::Key::Right)) {
		handleMovement(Directions::Right, m);
	}
	if (keyboard.checkInput(sf::Keyboard::Key::Down)) {
		handleMovement(Directions::Down, m);
	}
	if (keyboard.checkInput(sf::Keyboard::Key::Up)) {
		handleMovement(Directions::Up, m); // Debugg purpose only __DELETE__
	}
	if (keyboard.checkInput(sf::Keyboard::Key::R)) {
		rotateTetromino();
	}
}

void Tetromino::checkInput(std::vector<Mino>& t)
{
	
	if (keyboard.checkInput(sf::Keyboard::Key::Left)) {
		handleMovement(Directions::Left, t);
	}
	else if (keyboard.checkInput(sf::Keyboard::Key::Right)) {
		handleMovement(Directions::Right, t);
	}
	else if (keyboard.checkInput(sf::Keyboard::Key::Down)) {
		handleMovement(Directions::Down, t);
	}
	else if (keyboard.checkInput(sf::Keyboard::Key::Up)) {
		handleMovement(Directions::Up, t); // Debugg purpose only __DELETE__
	}
	else if (keyboard.checkInput(sf::Keyboard::Key::R)) {
		rotateTetromino();
	}
}


// NOTE(AloneTheKing): Need to make a fuction canMove how will move down and check if canMove if can't return false; and put mino[,] in std::vector of Minos, probably so i'll need to not pass as const, just as reference
void Tetromino::Update(std::vector<Mino>& Minos)
{
	checkInput(Minos);
	if (!onFloor) {
		//handleMovement(Directions::Down, Minos);
	}
}


Tetromino& Tetromino::operator=(const Tetromino& t)
{
	if (this == &t)
		return *this;
	
	mino.clear();
	
	Type = t.Type;
	onFloor = false;
	setMinoType();
	setTetrominoGeometry();
	setPosition(t.tPos);
	nRotation = 0;
	
	return *this;
}



