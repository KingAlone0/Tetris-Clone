#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "tetromino.hpp"
#include "renderWindow.hpp"
#include <ctime>
#include <random>
#include <thread>


short int scoreMultiplier(short int row);
TilesType getRandomTetromino();
void deleteRowAt(std::vector<Mino>& grid, unsigned short int h);
bool isRowFullAt(const std::vector<Mino>& grid, unsigned short int);
void setGrid(std::array<sf::Sprite, 56>& g);
void holdTetromino(Tetromino& tetromino, Tetromino& holded_tetromino, Tetromino& next_tetromino);
void nextTetromino(Tetromino& tetromino, Tetromino& next_tetromino);

void defeatMenu(RenderWindow* window, int score, bool* is_paused, bool* exit); 

void pauseMenu(RenderWindow* window, bool* is_paused, bool* exit);

void Tetris(RenderWindow& window);

#endif //GAME_H

