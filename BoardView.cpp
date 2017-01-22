#include "BoardView.hpp"

BoardView::BoardView():
    window          (nullptr),
    normalTex       (new sf::Texture),
    checkeredTex    (new sf::Texture),
    sprSiz          (sf::Vector2u(0, 0)),
    mapSiz          (sf::Vector2u(0, 0))
{
    checked = true;
}

void BoardView::draw()
{
    if(window != nullptr)
        window->draw(spr);
}

void BoardView::setCol(sf::Vector2u pos, sf::Color color)
{
    if(pos.x < 0 || pos.x >= mapSiz.x || pos.y < 0 || pos.y >= mapSiz.y)
        return;

    sf::Image normalCell, checkeredCell;

    normalCell.create(1, 1, color);
    checkeredCell.create(checkeredCellSiz.x, checkeredCellSiz.y, color);

    normalTex->update(normalCell, pos.x, pos.y);
    checkeredTex->update(checkeredCell, pos.x * checkeredCellSiz.x, pos.y * checkeredCellSiz.y);
}

void BoardView::setSprPos(sf::Vector2f pos)
{
    spr.setPosition(pos.x, pos.y);
}

void BoardView::setWin(sf::RenderWindow *win)
{
    window = win;
}




















