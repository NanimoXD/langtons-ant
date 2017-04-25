#ifndef Ant2_hpp
#define Ant2_hpp

#include "Direction2.hpp"
#include "Board2.hpp"

#include <SFML/Graphics.hpp>

struct colorRule
{
    sf::Color color;
    Direction2 direction;
    bool active;
};

class Ant2
{
public:
    Ant2(Board2 &board);

    Ant2(Board2 &board, uint32_t x, uint32_t y, Direction2 dir = Direction2::Up);

    void nextStep();

    void setPos(sf::Vector2u _pos);
    void setPos(uint32_t x, uint32_t y);

    void setShadow(sf::Vector2u _pos);
    void setShadow(uint32_t x, uint32_t y);

    void setDir(Direction2 dir);

    static std::vector<colorRule> colors;

    // Pobieranie wartości:
    // -----------------------------------

    sf::Vector2u        getPos()    {return pos;}

    sf::Vector2u        getShadow() {return shadow;}

    Direction2          getDir()    {return direction;}

private:
    Board2 *board;

    sf::Vector2u pos;

    sf::Vector2u shadow;

    Direction2 direction;

    void checkCell(uint8_t *id);
};

#endif // Ant2_hpp













