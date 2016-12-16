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
        const int number = 75;

        mainWin.reserve(number);

        mainWin.push();
        mainWin.get()->setTexture(mainBg);
        mainWin.get()->setScale(mainWin.winSize.x / mainBg.getSize().x / 2, mainWin.winSize.y / mainBg.getSize().y / 2);

        for(int i = 1; i < number; ++i)
        {
            mainWin.copy();
            mainWin.get()->setPosition(mainWin.winSize.x / ((number - 1) * 2) * i, mainWin.winSize.y / ((number - 1) * 2) * i);
        }
    }

    int lol = 0;
    bool XD = true;

    sf::Time time = sf::seconds(0);

    while(mainWin.start())
    {
        time += mainWin.clock();

        for(; time > sf::milliseconds(1000 / mainWin.size()); time -= sf::milliseconds(1000 / mainWin.size()))
        {
            // Takie małe coś a tyle radości XDD

            if(lol < mainWin.size() * 2 - 1 && XD)
            {
                mainWin.move(mainWin.size() - 1, lol % mainWin.size());
                ++lol;
            }
            else if(lol > 0 && !XD)
            {
                if(lol == mainWin.size() * 2 - 1) lol = mainWin.size() - 1;
                mainWin.move(0, lol);
                --lol;
            }
            else XD = !XD;

            // No lol XD
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














