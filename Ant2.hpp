#ifndef Ant2_hpp
#define Ant2_hpp

#include "Direction2.hpp"
#include "Board2.hpp"

#include <SFML/Graphics.hpp>

struct ruleColor
{
    sf::Color color;
    Direction2 direction;
};

class Ant2
{
public:
    Ant2(Board2 &board);

    Ant2(Board2 &board, uint32_t x, uint32_t y, Direction2 dir = Direction2::Up);

    void nextStep();

    void setPos(sf::Vector2u _pos);
    void setPos(uint32_t x, uint32_t y);

    void setDir(Direction2 dir);

    static std::vector<ruleColor> colors;

    // Pobieranie wartości:
    // -----------------------------------

    sf::Vector2u        getPos()    {return pos;}

    Direction2          getDir()    {return direction;}

private:
    Board2 *board;

    sf::Vector2u pos;

    Direction2 direction;
};

#endif // Ant2_hpp













