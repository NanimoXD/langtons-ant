#include "Board2.hpp"

#define defNum 0

Board2::Board2():
    area    (sf::Vector2i(0, 0))
{

}

Board2::Board2(uint32_t x, uint32_t y):
    area    (sf::Vector2i(0, 0))
{
    if(x > 1) addArea(x, Direction2::Right);
    if(y > 1) addArea(y, Direction2::Down);
}

void Board2::addArea(uint32_t exSize, Direction2 dir)
{
    if(!exSize) return;

    switch(dir)
    {
    case Direction2::Up:
    case Direction2::Down:
        {
            area.y += exSize;

            std::vector<uint8_t> addition;
            addition.reserve(exSize);

            for(uint32_t i = 0; i < exSize; ++i)
                addition.push_back(defNum);

            for(uint32_t i = 0; i < area.x; ++i)
                board[i].insert(dir == Direction2::Up ? board[i].begin() : board[i].end(), addition.begin(), addition.end());
        }
        break;
    case Direction2::Left:
    case Direction2::Right:
        {
            area.x += exSize;

            std::vector<uint8_t> addition;
            addition.reserve(area.y);

            for(uint32_t i = 0; i < area.y; ++i)
                addition.push_back(defNum);

            std::vector<std::vector<uint8_t>> exAddition;
            exAddition.reserve(exSize);

            for(uint32_t i = 0; i < exSize; ++i)
                exAddition.push_back(addition);

            board.insert(dir == Direction2::Left ? board.begin() : board.end(), exAddition.begin(), exAddition.end());
        }
        break;
    }
}

void Board2::clear()
{
    for(uint32_t i = 0; i < area.x; ++i)
        board[i].clear();

    board.clear();

    area.x = 0;
    area.y = 0;
}

#undef defNum








