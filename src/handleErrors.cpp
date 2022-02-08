#include "handleErrors.hpp"

bool Errors::hasErr = false;

void handleErrors(ErrorType err, std::string str)
{
   RenderWindow errorWindow("ERROR!", 100, 100); 
   sf::RectangleShape background;
   background.setSize(sf::Vector2f(100.f, 100.f));
   background.setPosition(0.f, 0.f);
   background.setFillColor(sf::Color::Red);

   // Put something on screen and handle de error by type
   while (errorWindow.isOpen())
   {
       sf::Event event;
       while (errorWindow.window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
           {
               errorWindow.close();
           }
       }
   }
}

