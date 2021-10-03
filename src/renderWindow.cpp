#include "renderWindow.hpp"

renderWindow::renderWindow(const std::string& windowTitle, unsigned int width, unsigned int height) : Title(windowTitle), width(width), height(height)
{
	window.create(sf::VideoMode(width, height), Title);
}