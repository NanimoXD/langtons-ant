#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <sstream>

#include "Veque.hpp"
#include "Button.hpp"
#include "MainWin.hpp"

int main()
{
    jk::MainWin mainWin;

    sf::Texture mainBg;
    if(mainBg.loadFromFile("Images/background.jpg"))
    {
        mainWin.sprites.push();
        mainWin.sprites.get()->setTexture(mainBg);
        mainWin.sprites.get()->setScale(mainWin.winSize.x / mainBg.getSize().x / 2, mainWin.winSize.y / mainBg.getSize().y / 2);

        for(int i = 1; i < 30; ++i)
        {
            mainWin.sprites.copy();
            mainWin.sprites.get()->setPosition(mainWin.winSize.x / 58 * i, mainWin.winSize.y / 58 * i);
        }
    }

    int lol = 0;
    bool XD = true;

    while(mainWin.start())
    {
        // Takie małe coś a tyle radości XDD

        mainWin.sprites.move(29, lol);
        if(lol < 29 && XD) ++lol;
        else if(lol > 0 && !XD) --lol;
        else XD = !XD;

        // No lol XD
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

void jk::MainWin::display()
{
    sprites.draw(window);
}












