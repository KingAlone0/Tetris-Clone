#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#ifdef _WIN32

#define NTDDI_VERSION 0x0A000006 //NTDDI_WIN10_RS5
// #define _WIN32_WINNT 0x0A00 // _WIN32_WINNT_WIN10, the _WIN32_WINNT macro must also be defined when defining NTDDI_VERSION
#include <windows.h>
#include <shobjidl.h>
#include <string>

#endif

#include <SFML/Graphics.hpp>
#include <renderWindow.hpp>
// UI Stuffs
#include "slider.hpp"
#include "checkBox.hpp"
#include "sound.hpp"
#include "button.hpp"
#include <functional>

#include <fstream>
#include <stdio.h>
#include <string>

void Options(RenderWindow& window);

void selectTexturePath();

void saveConfigs();
void loadConfigs();


#endif // OPTIONS_Hpp

