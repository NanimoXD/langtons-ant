#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <cstring>

#include "MainWin.hpp"

void createMap(MainWin &mainWin, sf::Texture &field)
{
    sf::Image ffield;
    ffield.create(1, 1, sf::Color(255, 255, 255));
    field.loadFromImage(ffield);

    const int mapx = 101;
    const int mapy = 101;

    mainWin.reserve(mapx * mapy);

    mainWin.push();
    mainWin.get()->setTexture(field);
    mainWin.get()->setScale(mainWin.winSize.x / field.getSize().x / mapx, mainWin.winSize.y / field.getSize().y / mapy);

    for(int i = 0; i < mapy; ++i)
    {
        for(int j = 0; j < mapx; ++j)
        {
            mainWin.copy();
            mainWin.get()->setPosition(j * mainWin.get()->getScale().x * field.getSize().x, i * mainWin.get()->getScale().y * field.getSize().y);
        }
    }
}

int main()
{
    MainWin mainWin;
    sf::Texture field;

    createMap(mainWin, field);

    int fps = 0;
    sf::Time second = sf::seconds(0);
    sf::Time milSec = sf::seconds(0);

    /* Taka sobie mrówka nie musi sie tworzyæ od nowa za ka¿dym razem :p */
    Ant a;
    a.setPosition(200, 200);
    a.setScale(0.2, 0.2);
    a.rotate(Direction::Left);

    while(mainWin.start())
    {
        /* Taka sobie mrówka */
        mainWin.drawSpr(a);

        ++fps;

        for(milSec += mainWin.clock(); milSec > sf::milliseconds(10); milSec -= sf::milliseconds(10))
        {
            mainWin.erase(mainWin.size() * 0.25);
            mainWin.erase(mainWin.size() * 0.5);
            mainWin.erase(mainWin.size() * 0.75);
        }

        for(second += mainWin.clock(); second > sf::seconds(1); second -= sf::seconds(1))
        {
            printf("Fps: %i\n", fps);
            fps = 0;
        }
    }

    return EXIT_SUCCESS;
}

void MainWin::events(sf::Event &event)
{
    if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        window.close();
        return;
    }
}














