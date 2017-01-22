#include "Ant.hpp"


Ant::Ant()
    : direction(Direction::Up)
{ }

void Ant::rotateAnt(Direction dir)
{
    direction = rotateDirection(direction, dir);
}

void Ant::setDirection(Direction dir)
{
    direction = dir;
}
