#include "MainWin.hpp"

MainWin::MainWin(sf::Vector2u winSiz, bool _fullscreen):
    window      (new sf::RenderWindow),
    fullscreen  (!_fullscreen)
{
    newWin(winSiz, _fullscreen);
}

void MainWin::newWin(sf::Vector2u winSize, bool _fullscreen)
{
    if(winSize == sf::Vector2u())
    {
        winSize.x = sf::VideoMode::getDesktopMode().width;
        winSize.y = sf::VideoMode::getDesktopMode().height;
    }

    if(fullscreen != _fullscreen)
    {
        fullscreen = !fullscreen;

        if(window->isOpen()) window->close();

        window->create(sf::VideoMode(winSize.x, winSize.y, sf::VideoMode::getDesktopMode().bitsPerPixel), "Ant XD", 7 + fullscreen);
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
    else
    {
        sf::FloatRect view(0, 0, winSize.x, winSize.y);

        if(view.width < 800) window->setSize(sf::Vector2u(800, view.height));
        if(view.height < 600) window->setSize(sf::Vector2u(view.width, 600));

        window->setView(sf::View(view));
    }
}

bool MainWin::isFullscreen()
{
    return fullscreen;
}




















