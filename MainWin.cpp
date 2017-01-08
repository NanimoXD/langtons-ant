#include "MainWin.hpp"

MainWin::MainWin(sf::Vector2u winSiz, bool _fullscreen):
    window      (new sf::RenderWindow)
{
    newWin(winSiz, _fullscreen);
}

void MainWin::newWin(sf::Vector2u winSize, bool _fullscreen)
{
    fullscreen = _fullscreen;

    if(fullscreen)
    {
        winSize.x = sf::VideoMode::getDesktopMode().width;
        winSize.y = sf::VideoMode::getDesktopMode().height;
    }

    if(window->isOpen()) window->close();

    window->create(sf::VideoMode(winSize.x, winSize.y, sf::VideoMode::getDesktopMode().bitsPerPixel), "Ant XD", 1 << (2 + fullscreen));
    window->setFramerateLimit(60);
    window->clear(sf::Color::Black);
    window->display();

    /* Przynajmniej do czasu naprawienia błędu #1168 (https://github.com/SFML/SFML/issues/1168) */
    #ifndef SFML_SYSTEM_LINUX
        sf::Image *icon = new sf::Image;

        if(icon->loadFromFile("Images/icon.png"))
            window->setIcon(icon->getSize().x, icon->getSize().y, icon->getPixelsPtr());
        delete icon;
    #endif
}

bool MainWin::isFullscreen()
{
    return fullscreen;
}




















