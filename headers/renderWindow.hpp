#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"


class renderWindow
{
    public:
    std::string Title;
    sf::RenderWindow window;
	unsigned int width;
	unsigned int height;
	private:
	
    public:
    renderWindow(const std::string& windowTitle, unsigned int width, unsigned int height);
    private:
	
};