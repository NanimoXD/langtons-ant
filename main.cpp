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

int main()
{
    jk::MainWin mainWin;

    sf::Texture mainBg;
    if(mainBg.loadFromFile("Images/background.jpg"))
    {
        const int mapx = 100;
        const int mapy = 100;

        mainWin.reserve(mapx * mapy);

        mainWin.push();
        mainWin.get()->setTexture(mainBg);
        mainWin.get()->setScale(mainWin.winSize.x / mainBg.getSize().x / mapx, mainWin.winSize.y / mainBg.getSize().y / mapy);

        for(int i = 0; i < mapx; ++i)
        {
            for(int j = 0; j < mapy; ++j)
            {
                mainWin.copy();
                mainWin.get()->setPosition(i * mainWin.get()->getScale().x * mainBg.getSize().x, j * mainWin.get()->getScale().y * mainBg.getSize().y);
                mainWin.copy();
                mainWin.get()->setColor(sf::Color(0, 0, 128));
            }
        }
    }

    int fps = 0;
    sf::Time second = sf::seconds(0);

    while(mainWin.start())
    {
        ++fps;

        second += mainWin.clock();
        if(second > sf::seconds(1))
        {
            second -= sf::seconds(1);

            mainWin.get(0)->setColor(sf::Color(255, 0, 0));

            printf("%i\n", fps);
            fps = 0;
        }
    }

    return EXIT_SUCCESS;
}

void jk::MainWin::events(sf::Event &event)
{
    if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        window.close();
        return;
    }
}














