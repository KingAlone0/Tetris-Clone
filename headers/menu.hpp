#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
#include "options.hpp"
#include "button.hpp"
#include "image.hpp"
#include "keyboard.hpp"
#include "thread"

#define TILE 16
#include <functional>

#include "renderWindow.hpp"
#include "handleErrors.hpp"

void Menu(RenderWindow &window);

