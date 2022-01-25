#ifndef CHECK_BOX_HPP
#define CHECK_BOX_HPP
#include "UI.hpp"

// TODO: Make it child of UI class
class CheckBox
{
    private:
    V2 pos;
    sf::RectangleShape box;
    bool pressed = false;
    sf::Clock pressedTime;
    ID id;

    public:
    CheckBox(float x, float y);
    void Update(RenderWindow* window);

    private:
    void setBox();
    void check(V2 mouse_pos);

};


#endif
