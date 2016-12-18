#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <cstring>

#include "Veque.hpp"
#include "Button.hpp"
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
    bool qwer = true;

    while(mainWin.start())
    {
        ++fps;

        second += mainWin.clock();
        if(second > sf::seconds(1))
        {
            second -= sf::seconds(1);

            for(int i = qwer; i < mainWin.size(); i += 2)
                mainWin.get(i)->setColor(sf::Color(0, 0, 255));

            for(int i = !qwer; i < mainWin.size(); i += 2)
                mainWin.get(i)->setColor(sf::Color(255, 0, 255));

            qwer = !qwer;

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














