#include "renderWindow.hpp"

RenderWindow::RenderWindow(const std::string& windowTitle, unsigned int width, unsigned int height) : Title(windowTitle), width(width), height(height)
{
    window.create(sf::VideoMode(width, height), Title);
}

V2 RenderWindow::getMousePosition()
{
    return V2(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
}

void RenderWindow::onResize()
{
    /*
	if (getSize().x != width || getSize().y != height) {
		setSize(sf::Vector2u(width, height));
	}
	
	float n_width = getSize().x;
	float n_height = getSize().y;
	float aspect_ratio = (float)width / height;
	view.setSize(n_width, n_height);
	
	float ratio_w = (float)n_width / width;
	float ratio_h = (float)n_height / height;
	
	float ratio = ratio_w > ratio_h ? ratio_h : ratio_w;
	
	n_width  = (float)width * ratio;
	n_height = (float)height * ratio;
	
	if (n_width > n_height) {
		view.setSize(width, n_height);
	} else {
		view.setSize(n_width, height);
	}
	view.setCenter((float)width / 2, (float)height / 2);
	//view.setViewport(sf::FloatRect(0.f, 0.f, 1, 1));
	
	setView(view);
	*/
	/*
	m_view.setSize((float)window.getSize().x, (float)window.getSize().y);
	if ((double)window.getSize().x / window.getSize().y == aspect_ratio)  {
		view = window.getDefaultView(); // don't that, need to pick up last aspect useful
		std::cout << window.getSize().x << " : " << window.getSize().y << std::endl;
	}
	window.setView(view);
	window_size = sf::Vector2f(window.getSize());
	*/
}

