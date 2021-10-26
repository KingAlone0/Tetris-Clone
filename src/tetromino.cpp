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
        mino[0].setSpriteLocation(sf::Vector2f(0.f * TILE, 2.f * TILE));
        mino[0].setIndex(8);
        mino[1].setSpriteLocation(sf::Vector2f(1.f * TILE, 2.f * TILE));
        mino[1].setIndex(9);
        mino[2].setSpriteLocation(sf::Vector2f(2.f * TILE, 2.f * TILE));
        mino[2].setIndex(10);
        mino[3].setSpriteLocation(sf::Vector2f(3.f * TILE, 2.f * TILE));
        mino[3].setIndex(11);
        break;
        case TilesType::O:
        mino[0].setSpriteLocation(sf::Vector2f(0.f, 0.f));
        mino[0].setIndex(0);
        mino[1].setSpriteLocation(sf::Vector2f(1.f * TILE, 0.f * TILE));
        mino[1].setIndex(1);
        mino[2].setSpriteLocation(sf::Vector2f(0.f * TILE, 1.f * TILE));
        mino[2].setIndex(4);
        mino[3].setSpriteLocation(sf::Vector2f(1.f * TILE, 1.f * TILE));
        mino[3].setIndex(5);
        break;
        case TilesType::T:
        mino[0].setSpriteLocation(sf::Vector2f(0.f * TILE, 1.f * TILE));
        mino[0].setIndex(3, 3);
        mino[1].setSpriteLocation(sf::Vector2f(1.f * TILE, 1.f * TILE));
        mino[1].setIndex(4, 3);
        mino[2].setSpriteLocation(sf::Vector2f(2.f * TILE, 1.f * TILE));
        mino[2].setIndex(5, 3);
        mino[3].setSpriteLocation(sf::Vector2f(1.f * TILE, 0.f * TILE));
        mino[3].setIndex(1, 3);
        break;
        case TilesType::J:
        mino[0].setSpriteLocation(sf::Vector2f(0.f * TILE, 2.f * TILE));
        mino[0].setIndex(3, 3);
        mino[1].setSpriteLocation(sf::Vector2f(1.f * TILE, 2.f * TILE));
        mino[1].setIndex(4, 3);
        mino[2].setSpriteLocation(sf::Vector2f(2.f * TILE, 2.f * TILE));
        mino[2].setIndex(5, 3);
        mino[3].setSpriteLocation(sf::Vector2f(0.f * TILE, 1.f * TILE));
        mino[3].setIndex(0, 3);
        break;
        case TilesType::L:
        mino[0].setSpriteLocation(sf::Vector2f(0.f * TILE, 1.f * TILE));
        mino[0].setIndex(3, 3);
        mino[1].setSpriteLocation(sf::Vector2f(1.f * TILE, 1.f * TILE));
        mino[1].setIndex(4, 3);
        mino[2].setSpriteLocation(sf::Vector2f(2.f * TILE, 1.f * TILE));
        mino[2].setIndex(5, 3);
        mino[3].setSpriteLocation(sf::Vector2f(2.f * TILE, 2.f * TILE));
        mino[3].setIndex(8, 3);
        break;
        case TilesType::Z:
        mino[0].setSpriteLocation(sf::Vector2f(0.f * TILE, 2.f * TILE));
        mino[0].setIndex(3, 3);
        mino[1].setSpriteLocation(sf::Vector2f(1.f * TILE, 2.f * TILE));
        mino[1].setIndex(4, 3);
        mino[2].setSpriteLocation(sf::Vector2f(1.f * TILE, 1.f * TILE));
        mino[2].setIndex(1, 3);
        mino[3].setSpriteLocation(sf::Vector2f(2.f * TILE, 1.f * TILE));
        mino[3].setIndex(2, 3);
        break;
        case TilesType::S:
        mino[0].setSpriteLocation(sf::Vector2f(0.f * TILE, 1.f * TILE));
        mino[0].setIndex(0, 3);
        mino[1].setSpriteLocation(sf::Vector2f(1.f * TILE, 1.f * TILE));
        mino[1].setIndex(1, 3);
        mino[2].setSpriteLocation(sf::Vector2f(1.f * TILE, 2.f * TILE));
        mino[2].setIndex(4, 3);
        mino[3].setSpriteLocation(sf::Vector2f(2.f * TILE, 2.f * TILE));
        mino[3].setIndex(5, 3);
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

void Tetromino::setPosition(sf::Vector2f newPosition)
{
	for (int i = 0; i < 4; ++i) {
		sf::Vector2f n_pos(newPosition.x + mino[i].getPosition().x, newPosition.y + mino[i].getPosition().y);
        mino[i].setSpriteLocation(n_pos);
    }
}

void Tetromino::hardDrop(std::vector<Mino>& minos)
{
	sf::Clock c;
	sf::Time  t;
	
	V2 gridFloor(0.f, 24 * TILE);
	float ttt[3] = {0.f, 0.f, 0.f};
	// Create a transform with these variables ? As a pointer to not need to keep updating
	for (Mino m : mino) {
		if (ttt[0] == 0.f || m.getPosition().x < ttt[0]) { // 0 = Minor x
			ttt[0] = m.getPosition().x;
		}
		if (ttt[1] == 0.f || m.getPosition().x > ttt[1]) { // 1 = Bigger x
			ttt[1] = m.getPosition().x;
		}
		if (ttt[2] == 0.f || m.getPosition().y > ttt[2]) { // 2 = Minor y
			ttt[2] = m.getPosition().y;
		}
	}
	
	if (minos.size() > 56)
	{
		for (size_t i = 55; i < minos.size(); ++i)
		{
			if (minos[i].getPosition().x >= ttt[0] && minos[i].getPosition().x <= ttt[1])
			{
				if (minos[i].getPosition().y < gridFloor.y)
				{
					gridFloor = minos[i].getPosition();
				}
			}
		}
	}
	sf::Vector2f n_pos(0.f , gridFloor.y - ttt[2] - TILE); // The new position is equal floor - one tile.
	
	for (size_t i = 0; i < mino.size(); ++i) {
		mino[i].handleMovement(n_pos);
	}
	
	onFloor = true;
	// handleMovement(Directions::Down, minos);
	
	t = c.getElapsedTime(); // Time to the pieces go down.
	std::cout << "Execution Time: " << t.asSeconds() << std::endl;
}

void Tetromino::handleMovement(Directions d, std::vector<Mino>& Minos, bool Collided)
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
	else if (d == Directions::None)
		direction = sf::Vector2f(0.f, 0.f); // Keep.
	
	for (int i = 0; i < 4; ++i) {
        mino[i].handleMovement(direction);
	}
	
	if (!canMove(Minos) && !Collided) {
		direction = d == Directions::Left ? sf::Vector2f(16.f, 0.f) : sf::Vector2f(-16.f, 0.f);
		if (d != Directions::Left && d != Directions::Right) {
			direction = d == Directions::Down ? sf::Vector2f(0.f, -16.f) : sf::Vector2f(0.f, 16.f);
		}
		for (int i = 0; i < 4; ++i) {
			mino[i].handleMovement(direction);
		}
		
		if (d == Directions::Down && onFloor == false) {
			onFloor = true;
		}
		return;
	}
	onFloor = false;
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
void Tetromino::rotateTetromino(std::vector<Mino>& minos)
{
	sf::Clock c;
	sf::Time t;
	
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
		if (nRotation > 1)
			nRotation = 0;
	}
	bool doubleCheck = false;
	
    updateRotationPosition();
	Directions movement;
	bool hasCollided = false;
	wallKick(minos);
	
	t = c.getElapsedTime();// TODO(AloneTheKing): So fucking slow
	// std::cout << t.asSeconds() << std::endl; // check Time
}

void Tetromino::updateRotationPosition()
{
	for (int i = 0; i < 4; ++i)
	{
		sf::Vector2f position = mino[i].getPosition();
		Index index = mino[i].getRotatedIndex();
		index.updateCoordinates();
		Index n_index = mino[i].updateIndexPosition(nRotation); // new index.
		
		short int n_x, n_y;
		n_x = n_index.x - index.x;
		n_y = n_index.y - index.y;
		
		mino[i].setPosition(position.x + n_x * TILE , position.y + n_y * TILE);
	}
}

void Tetromino::wallKick(std::vector<Mino>& minos)
{
	sf::Clock c;
	bool b_WK = false;
	
	V2 WK[7] = { V2(0, 0), V2(0, -16), V2(-16, 0), V2(16, 0), V2(-16, -16), V2(0, 32), V2(-16, 32) };
	
	for (int i = 0; i < 7; ++i) {
		for (size_t m = 0; m < mino.size(); ++m) {
			mino[m].handleMovement(WK[i]);
		}
		if (canMove(minos)) {
			b_WK = true;
			break;
		}
		else {
			V2 v2t = WK[i] * -1;
			for (size_t m = 0; m < mino.size(); ++m) {
				mino[m].handleMovement(v2t);
			}
		}
	}
	if (!b_WK)
	{
		updateRotationPosition(); // NOTE(AloneTheKing): Don't know if this is realy necessary.
		nRotation--;
	}
	// std::cout << "Execution Time " << c.getElapsedTime().asSeconds() << std::endl;
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
		rotateTetromino(t);
	}
	if (keyboard.checkInput(sf::Keyboard::Key::Space)) {
		hardDrop(t); // Need to implement
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
