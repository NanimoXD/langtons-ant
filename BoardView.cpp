#include "BoardView.hpp"

BoardView::BoardView():
    window          (nullptr),
    tex             (new sf::Texture),
    area            (sf::IntRect(0, 0, 1, 1)),
    defCol          (sf::Color(223, 223, 223))
{
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
    if(pos.x < 0 || pos.x >= tex->getSize().x || pos.y < 0 || pos.y >= tex->getSize().y)
        return;

    sf::Image cell;
    cell.create(1, 1, color);

    tex->update(cell, pos.x, pos.y);
}

void BoardView::update()
{
    if(spr.getTexture() == NULL || window == nullptr)
        return;

    sprSiz = sf::Vector2f((float)window->getSize().x * 0.94 - 200, (float)window->getSize().y * 0.88 - 75);

    spr.setPosition(sf::Vector2f((float)window->getSize().x * 0.02, (float)window->getSize().y * 0.04));
    spr.setScale(sprSiz.x / (float)area.width, sprSiz.y / (float)area.height);

    bgSprite.setPosition(sf::Vector2f((float)window->getSize().x * 0.01, (float)window->getSize().y * 0.02));
    bgSprite.setScale((float)window->getSize().x * 0.96 - 200, (float)window->getSize().y * 0.92 - 75);
}

void BoardView::setMapSiz(sf::Vector2u siz)
{
    sf::Image qubby = tex->copyToImage(), background;

    delete tex;
    tex = new sf::Texture;
    tex->create(siz.x, siz.y);

    background.create(siz.x, siz.y, defCol);
    tex->update(background);
    if(qubby.getSize().x > 0 && qubby.getSize().y > 0) tex->update(qubby);

    spr.setTexture(*tex);

    update();
}

bool BoardView::setView(sf::IntRect pos)
{
    if(pos.width > (signed)tex->getSize().x) pos.width = (signed)tex->getSize().x;
    if(pos.height > (signed)tex->getSize().y) pos.height = (signed)tex->getSize().y;

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




















