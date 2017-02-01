#include "MainWin.hpp"

MainWin::MainWin(sf::Vector2u winSiz, bool _fullscreen):
    window      (new sf::RenderWindow),
    fullscreen  (!_fullscreen)
{
    newWin(winSiz, _fullscreen);
}

void MainWin::newWin(sf::Vector2u winSiz, bool _fullscreen)
{
    if(winSiz == sf::Vector2u())
    {
        winSiz.x = sf::VideoMode::getDesktopMode().width;
        winSiz.y = sf::VideoMode::getDesktopMode().height;
    }

    if(fullscreen != _fullscreen)
    {
        fullscreen = !fullscreen;

        window->create(sf::VideoMode(winSiz.x, winSiz.y, sf::VideoMode::getDesktopMode().bitsPerPixel), "Ant XD", 7 + fullscreen);
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
        sf::FloatRect view(0, 0, winSiz.x, winSiz.y);

        if(view.width < 800) window->setSize(sf::Vector2u(800, view.height));
        if(view.height < 600) window->setSize(sf::Vector2u(view.width, 600));

        window->setView(sf::View(view));
    }
}

bool MainWin::isFullscreen()
{
    return fullscreen;
}




















