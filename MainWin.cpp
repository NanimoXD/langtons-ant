#include "MainWin.hpp"

MainWin::MainWin(sf::Vector2f winSize):
    window      (new sf::RenderWindow)
{
    window->create(sf::VideoMode(winSize.x, winSize.y, sf::VideoMode::getDesktopMode().bitsPerPixel), "Ant XD", sf::Style::Close);
    window->setFramerateLimit(60);
    window->clear(sf::Color::Black);
    window->display();

    /* Przynajmniej do czasu naprawienia błędu #1168 (https://github.com/SFML/SFML/issues/1168) */
#ifndef SFML_SYSTEM_LINUX
    sf::Image *icon = new sf::Image;
    rubbish.push(icon);

    if(icon->loadFromFile("Images/icon.png"))
        window->setIcon(icon->getSize().x, icon->getSize().y, icon->getPixelsPtr());
#endif
}

MainWin::~MainWin()
{
    delete window;

    delete (sf::Image*)         rubbish.front(); rubbish.pop();
    delete (sf::Texture*)       rubbish.front(); rubbish.pop();
}

int MainWin::main()
{
    Button button;
    button.setDefCol(255, 0, 0);
    button.setHovCol(0, 255, 0);
    button.setActCol(0, 0, 255);
    button.setWin(*window);
    button.setTex("Images/background.jpg");
    button.setSiz(300, 100);
    button.setPos(window->getSize().x / 2 - button.getSiz().x / 2, window->getSize().y / 2 - button.getSiz().y / 2);

    sf::Text buttonText;
    buttonText.setFillColor(sf::Color(0, 0, 0));
    buttonText.setOutlineColor(sf::Color(255, 255, 255));
    buttonText.setOutlineThickness(1);
    buttonText.setString("Lol no witam :D");
    button.setTxt(buttonText);

    bool qwer = true;
    Veque map;
    createMap(map);

    int fps = 0;
    sf::Time second = sf::seconds(0);
    sf::Time milSec = sf::seconds(0);

    Ant a;
    a.setPosition(200, 200);
    a.setScale(0.2, 0.2);
    a.rotate(Direction::Left);

    while(start())
    {
        while(window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window->close();
            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                    window->close();
            }
            else
            {
                // Przycisk przycisk :D
                if(button.button(event))
                {
                    for(int i = qwer; i < map.size(); i += 2)
                        map.get(i)->setColor(sf::Color(0, 255, 255));

                    for(int i = !qwer; i < map.size(); i += 2)
                        map.get(i)->setColor(sf::Color(0, 0, 255));

                    qwer = !qwer;
                }
            }
        }

        ++fps;

        for(milSec += time; milSec > sf::milliseconds(10); milSec -= sf::milliseconds(10))
        {
            map.erase(map.size() * 0.25);
            map.erase(map.size() * 0.5);
            map.erase(map.size() * 0.75);
        }

        for(second += time; second > sf::seconds(1); second -= sf::seconds(1))
        {
            printf("Fps: %i\n", fps);
            fps = 0;
        }

        map.draw(*window);

        window->draw(a);

        button.draw();
    }

    return EXIT_SUCCESS;
}

bool MainWin::start()
{
    time = clock.getElapsedTime();
    clock.restart();

    window->display();
    window->clear(sf::Color::Black);

    return window->isOpen();
}

void MainWin::createMap(Veque &map)
{
    sf::Image ffield;
    ffield.create(1, 1, sf::Color(255, 255, 255));

    sf::Texture *field = new sf::Texture;
    field->loadFromImage(ffield);

    const int mapx = 101;
    const int mapy = 101;

    map.push();
    map.get()->setTexture(*field);
    map.get()->setScale(window->getSize().x / field->getSize().x / mapx, window->getSize().y / field->getSize().y / mapy);

    for(int i = 0; i < mapy; ++i)
    {
        for(int j = 0; j < mapx; ++j)
        {
            map.copy();
            map.get()->setPosition(j * window->getSize().x / mapx, i * window->getSize().y / mapy);
        }
    }

    for(int i = 0; i < map.size(); i += 2)
        map.get(i)->setColor(sf::Color(0, 255, 255));

    for(int i = 1; i < map.size(); i += 2)
        map.get(i)->setColor(sf::Color(0, 0, 255));

    map.erase(0);
}














