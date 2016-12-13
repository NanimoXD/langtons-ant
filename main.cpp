#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <sstream>

#include "Veque.hpp"
#include "Button.hpp"


int main()
{
    jk::Veque qwer;

    sf::RenderWindow window;

    sf::Vector2f winSize(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 1.5);



    sf::Texture bgTexture;
    bgTexture.loadFromFile("Images/background.jpg");

    qwer.push();
    qwer.get()->setTexture(bgTexture);
    qwer.get()->setScale(winSize.x / bgTexture.getSize().x / 2, winSize.y / bgTexture.getSize().y / 2);

    for(int i = 1; i < 30; ++i)
    {
        qwer.copy();
        qwer.get()->setPosition(winSize.x / 58 * i, winSize.y / 58 * i);
    }

    window.create(sf::VideoMode(winSize.x, winSize.y, sf::VideoMode::getDesktopMode().bitsPerPixel), "Cosik Fajnego", sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    window.clear(sf::Color::Black);
    qwer.draw(window);
    window.display();

    sf::Image icon;
    if(icon.loadFromFile("Images/icon.png"))
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    int lol = 0;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
                return EXIT_SUCCESS;
            }
        }

        // Takie ma�e co� a tyle rado�ci XDD

        qwer.move(29, lol);
        if(lol < 29) ++lol;
        else lol = 0;

        // No lol XD

        window.clear(sf::Color::Black);

        qwer.draw(window);

        window.display();
    }

    return EXIT_SUCCESS;
}














