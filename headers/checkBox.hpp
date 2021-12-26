#ifndef CHECK_BOX_HPP
#define CHECK_BOX_HPP
#include "UI.hpp"

class CheckBox
{
    private:
    V2 pos;
    sf::RectangleShape box;
    bool pressed = false;
    sf::Clock pressedTime;

    public:
    CheckBox(float x, float y);
    void Update(sf::RenderWindow* window);

    private:
    void setBox();
    void check(V2 mouse_pos);

};


#endif
