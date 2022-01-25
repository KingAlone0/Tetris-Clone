#ifndef MOUSE_HPP
#define MOUSE_HPP
#include "types.hpp"

class Mouse
{
    public:
    Mouse(const Mouse&) = delete;
    static bool isActive();
    static void setActive(ID);
    static void setInactive();
    static ID getID();


    private:
    Mouse() {}

    static ID currentID; // Mayba a ptr to a ID() ?
    static bool active;

    static Mouse s_Instance;

};

#endif //  MouseHpp

