#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
#include "types.hpp"


// Maybe make it child of sf::RenderWindow again
class RenderWindow
{
    public:
    std::string Title;
	unsigned int width;
	unsigned int height;
	sf::View view = window.getView();
    sf::RenderWindow window;
	private:
	
    public:
    RenderWindow(const std::string& windowTitle, unsigned int width, unsigned int height);
    void draw(const sf::Drawable& image) { window.draw(image); }
    void display() { window.display(); }
    void clear() { window.clear(); }
    bool isOpen() { return window.isOpen(); }
    void close() { window.close(); }
    V2 getMousePosition();

	
	
    private:

    void onResize();

};
