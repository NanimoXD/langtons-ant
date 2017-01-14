#include "Ant.hpp"

Ant::Ant()
    : direction(Direction::Up)
{ }

Ant::~Ant()
{ }

void Ant::rotateAnt(Direction dir)
{
    Direction prev_dir = direction;
    direction = rotateDirection(direction, dir);
    directionChanged(prev_dir);
}

void Ant::setDirection(Direction dir)
{
    Direction prev_dir = direction;
    direction = dir;
    directionChanged(prev_dir);
}

void Ant::directionChanged(Direction /*previous_direction*/)
{ }
