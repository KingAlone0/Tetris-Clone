#include "mouse.hpp"
bool Mouse::active = false;
ID Mouse::currentID = ID();

bool Mouse::isActive()
{
    return active;
}

ID Mouse::getID()
{
    return currentID;
}

void Mouse::setActive(ID newID)
{
    active = true;
    currentID = newID;
}

void Mouse::setInactive()
{
    active = false;
}

Mouse Mouse::s_Instance;

