/* date = October 14th 2021 0:29 pm */
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "tetromino.hpp"
#include "renderWindow.hpp"
#include <ctime>
#include <random>


short int scoreMultiplier(short int row);
TilesType getRandomTetromino();
void deleteRowAt(std::vector<Mino>& grid, unsigned short int h);
bool isRowFullAt(const std::vector<Mino>& grid, unsigned short int);
void setGrid(std::array<sf::Sprite, 56>& g);
void holdTetromino(Tetromino& tetromino, Tetromino& holded_tetromino, Tetromino& next_tetromino);
void nextTetromino(Tetromino& tetromino, Tetromino& next_tetromino);

void Tetris(sf::RenderWindow& window);

#endif //GAME_H
