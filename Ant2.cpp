#include "Ant2.hpp"

std::vector<colorRule> Ant2::colors;

Ant2::Ant2(Board2 &board):
    board       (&board),
    pos         (sf::Vector2u(0, 0)),
    shadow      (sf::Vector2u(0, 0)),
    direction   (Direction2::Up)
{

}

Ant2::Ant2(Board2 &board, uint32_t x, uint32_t y, Direction2 dir):
    board       (&board),
    pos         (sf::Vector2u(x, y)),
    shadow      (sf::Vector2u(x, y)),
    direction   (dir)
{

}

void Ant2::nextStep()
{
    uint8_t *cell = &board->getCell(pos);

    checkCell(cell);

    rotateDirection2(direction, colors[*cell].direction);

    ++*cell;

    checkCell(cell);

    shadow = pos;

    switch(direction)
    {
    case Direction2::Down:
        ++pos.y;
        break;
    case Direction2::Left:
        --pos.x;
        break;
    case Direction2::Right:
        ++pos.x;
        break;
    case Direction2::Up:
        --pos.y;
        break;
    }
}

void Ant2::setPos(sf::Vector2u _pos)
{
    pos = _pos;
}

void Ant2::setPos(uint32_t x, uint32_t y)
{
    pos.x = x;
    pos.y = y;
}

void Ant2::setShadow(sf::Vector2u _pos)
{
    pos = _pos;
}

void Ant2::setShadow(uint32_t x, uint32_t y)
{
    pos.x = x;
    pos.y = y;
}

void Ant2::setDir(Direction2 dir)
{
    direction = dir;
}

void Ant2::checkCell(uint8_t *cell)
{
    if(*cell >= colors.size())
        *cell = 0;

    while(!colors[*cell].active)
    {
        ++*cell;

        if(*cell >= colors.size())
            *cell = 0;
    }
}












