#ifndef Board2_hpp
#define Board2_hpp

#include "Direction2.hpp"

#include <SFML/System.hpp>
#include <vector>

class Board2
{
public:
    Board2();                                                   // Kostruktor

    Board2(uint32_t x, uint32_t y);                             // konstruktor używa addArea()
                                                                // ustawiając mape do podanej wielkości

    void addArea(uint32_t exSize, Direction2 dir);              // Poszerza mape o 'exSize' po 'dir' stronie

    void clear();                                               // Usuwa wszystkie elementy z mapy

    // Pobieranie wartości:
    // ----------------------------------------------------------

    uint8_t         &getCell(uint32_t x, uint32_t y)    {return board[x][y];}
    uint8_t         &getCell(sf::Vector2u coord)        {return board[coord.x][coord.y];}

    sf::Vector2u    getSiz()                            {return area;}

private:
    sf::Vector2u area;                                          // Wielkosć mapy

    std::vector<std::vector<uint8_t>> board;                    // Mapa ;)
};

#endif // Board2_hpp















