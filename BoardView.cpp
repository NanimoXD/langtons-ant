#include "BoardView.hpp"

BoardView::BoardView():
    window          (nullptr),
    area            (sf::IntRect(0, 0, 1, 1)),
    defCol          (sf::Color(223, 223, 223))
{
    cell.create(1, 1, sf::Color(defCol));
    tex.create(1, 1);
    tex.update(cell);
    spr.setTexture(tex);

    sf::Image bgImg;
    bgImg.create(1, 1, sf::Color::Black);
    bgTexture.create(1, 1);
    bgTexture.update(bgImg);
    bgSprite.setTexture(bgTexture);
}

void BoardView::draw()
{
    if(window != nullptr)
    {
        window->draw(bgSprite);
        window->draw(spr);
    }
}

void BoardView::setCol(sf::Vector2u pos, sf::Color color)
{
    if(pos.x >= tex.getSize().x || pos.y >= tex.getSize().y)
        return;

    cell.setPixel(0, 0, color);

    tex.update(cell, pos.x, pos.y);
}

void BoardView::update()
{
    if(spr.getTexture() == NULL || window == nullptr)
        return;

    sprSiz = sf::Vector2f((float)window->getSize().x * 0.96 - 200 - 10, (float)window->getSize().y * 0.92 - 75 - 10);

    spr.setPosition(sf::Vector2f((float)window->getSize().x * 0.01 + 5, (float)window->getSize().y * 0.02 + 5));
    spr.setScale(sprSiz.x / (float)area.width, sprSiz.y / (float)area.height);

    bgSprite.setPosition(sf::Vector2f((float)window->getSize().x * 0.01, (float)window->getSize().y * 0.02));
    bgSprite.setScale((float)window->getSize().x * 0.96 - 200, (float)window->getSize().y * 0.92 - 75);
}

void BoardView::addArea(uint16_t extend, Direction dir)
{
    sf::Vector2u siz = tex.getSize();
    sf::Image qubby = tex.copyToImage(),
              background;

    switch(dir)
    {
    case Direction::Left:
    case Direction::Right:
        siz.x += extend;
        break;
    case Direction::Up:
    case Direction::Down:
        siz.y += extend;
        break;
    }

    tex.create(siz.x, siz.y);
    background.create(siz.x, siz.y, defCol);

    tex.update(background);

    switch(dir)
    {
    case Direction::Up:
        tex.update(qubby, 0, extend);
        break;
    case Direction::Left:
        tex.update(qubby, extend, 0);
        break;
    case Direction::Right:
    case Direction::Down:
        tex.update(qubby);
        break;
    }

    update();
}

bool BoardView::setView(sf::IntRect pos)
{
    if(pos.width > (signed)tex.getSize().x) pos.width = (signed)tex.getSize().x;
    if(pos.height > (signed)tex.getSize().y) pos.height = (signed)tex.getSize().y;

    area = pos;

    spr.setTextureRect(area);
    update();

    return true;
}

void BoardView::setDefCol(sf::Color col)
{
    defCol = col;
}

void BoardView::setWin(sf::RenderWindow *win)
{
    window = win;
    update();
}




















