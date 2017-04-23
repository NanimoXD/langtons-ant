#include "Ant2.hpp"

std::vector<ruleColor> Ant2::colors;

Ant2::Ant2(Board2 &board):
    board       (&board),
    pos         (sf::Vector2u(0, 0)),
    direction   (Direction2::Up)
{

}

Ant2::Ant2(Board2 &board, uint32_t x, uint32_t y, Direction2 dir):
    board       (&board),
    pos         (sf::Vector2u(x, y)),
    direction   (dir)
{

}

void Ant2::nextStep()
{
    uint8_t *cell = &board->getCell(pos);

    if(*cell >= colors.size()) return;

    rotateDirection2(direction, colors[*cell].direction);

    ++*cell;

    if(*cell >= colors.size())
        *cell = 0;

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

void Ant2::setDir(Direction2 dir)
{
    direction = dir;
}














