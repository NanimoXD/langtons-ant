#include "Ant.hpp"


Ant::Ant()
    : direction(Direction::Up)
{ }

Ant::Ant(const sf::Vector2u &position, Direction dir)
{
    on_board_position = position;
    direction = dir;
}

void Ant::rotateAnt(Direction dir)
{
    direction = rotateDirection(direction, dir);
}
