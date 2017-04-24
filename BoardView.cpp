#include "BoardView.hpp"

BoardView::BoardView():
    window          (nullptr),
    center          (sf::Vector2u(0, 0)),
    defCol          (sf::Color(223, 223, 223))
{
    newBoard();

    spr.setTexture(tex);

    sf::Image bgImg;
    bgImg.create(1, 1, sf::Color::Black);
    bgTexture.create(1, 1);
    bgTexture.update(bgImg);
    bgSprite.setTexture(bgTexture);
}

void BoardView::newBoard()
{
    cell.create(1, 1, sf::Color(defCol));
    tex.create(1, 1);
    tex.update(cell);

    area = sf::IntRect(0, 0, 1, 1);
    viewScl = 1;
}

void BoardView::draw()
{
    if(window != nullptr)
    {
        window->draw(bgSprite);
        window->draw(spr);
    }
}

bool BoardView::setCol(sf::Vector2u pos, sf::Color color)
{
    if(pos.x >= tex.getSize().x || pos.y >= tex.getSize().y)
        return false;

    cell.setPixel(0, 0, color);

    tex.update(cell, pos.x, pos.y);

    return true;
}

void BoardView::update()
{
    if(window == nullptr)
        return;

    spr.setPosition(sf::Vector2f((float)window->getSize().x * 0.01 + 5, (float)window->getSize().y * 0.02 + 5));
    spr.setScale((float)(window->getSize().x * 0.96 - 200 - 10) / (float)area.width, (float)(window->getSize().y * 0.92 - 75 - 10) / (float)area.height);

    bgSprite.setPosition(sf::Vector2f((float)window->getSize().x * 0.01, (float)window->getSize().y * 0.02));
    bgSprite.setScale((float)window->getSize().x * 0.96 - 200, (float)window->getSize().y * 0.92 - 75);
}

void BoardView::addArea(uint16_t extend, Direction2 dir)
{
    sf::Vector2u siz = tex.getSize();
    sf::Image qubby = tex.copyToImage(),
              background;

    switch(dir)
    {
    case Direction2::Left:
    case Direction2::Right:
        siz.x += extend;
        break;
    case Direction2::Up:
    case Direction2::Down:
        siz.y += extend;
        break;
    }

    tex.create(siz.x, siz.y);
    background.create(siz.x, siz.y, defCol);

    tex.update(background);

    switch(dir)
    {
    case Direction2::Up:
        tex.update(qubby, 0, extend);
        break;
    case Direction2::Left:
        tex.update(qubby, extend, 0);
        break;
    case Direction2::Right:
    case Direction2::Down:
        tex.update(qubby);
        break;
    }

    update();
}

void BoardView::setCenter(sf::Vector2i pos)
{
    if(pos != center)
    {
        if(pos.x > (signed)tex.getSize().x - 1) pos.x = (signed)tex.getSize().x - 1;
        else if(pos.x < 0) pos.x = 0;

        if(pos.y > (signed)tex.getSize().y - 1) pos.y = (signed)tex.getSize().y - 1;
        else if(pos.y < 0) pos.y = 0;

        center = pos;
    }

    area.left = center.x - area.width / 2;
    area.top = center.y - area.height / 2;

    if(area.left + area.width > (signed)tex.getSize().x) area.left = (signed)tex.getSize().x - area.width;
    else if(area.left < 0) area.left = 0;
    if(area.top + area.height > (signed)tex.getSize().y) area.top = (signed)tex.getSize().y - area.height;
    else if(area.top < 0) area.top = 0;

    spr.setTextureRect(area);
}

void BoardView::setViewSiz(sf::Vector2u siz)
{
    siz.x += 1 - siz.x % 2;
    siz.y += 1 - siz.x % 2;

    if(siz.x > tex.getSize().x) siz.x = tex.getSize().x;
    else if(siz.x < 5) siz.x = 5;

    if(siz.y > tex.getSize().y) siz.y = tex.getSize().y;
    else if(siz.y < 5) siz.y = 5;

    area.width = siz.x;
    area.height = siz.y;

    setCenter(center);
    update();
}

void BoardView::setViewScl(float scl)
{
    if(scl > 1) scl = 1;
    else if(scl < 0) scl = 0;

    viewScl = scl;

    setViewSiz(sf::Vector2u(tex.getSize().x * viewScl, tex.getSize().y * viewScl));
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




















