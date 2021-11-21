#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
#include "types.hpp"


class RenderWindow : public sf::RenderWindow
{
    public:
    std::string Title;
	unsigned int width;
	unsigned int height;
	sf::View view = getView();
	private:
	
    public:
    RenderWindow(const std::string& windowTitle, unsigned int width, unsigned int height);
	
	
	
    private:
	
	void onResize() override;
	
};