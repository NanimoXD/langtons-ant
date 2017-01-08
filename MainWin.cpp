#include "MainWin.hpp"

MainWin::MainWin(sf::Vector2u winSize, bool fullScreen):
    window              (new sf::RenderWindow),
    isFullScreen        (fullScreen)
{
    if(fullScreen)
    {
        winSize.x = sf::VideoMode::getDesktopMode().width;
        winSize.y = sf::VideoMode::getDesktopMode().height;
    }

    window->create(sf::VideoMode(winSize.x, winSize.y, sf::VideoMode::getDesktopMode().bitsPerPixel), "Ant XD", 1 << (2 + fullScreen));
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

MainWin::~MainWin()
{
    delete window;
}

int MainWin::main()
{
    Button button[5];
    setupButtons(button, 5);    /*  0) Start / Stop
                                 *  1) Wyjscie
                                 *  2) Opcje
                                 *  3) <
                                 *  4) >
                                 */

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

            if(button[0].button(event)) // Start / Stop
            {
                if(button[0].getTxt().getString() == "Start")
                {
                    button[0].setTxt("Stop");
                }
                else
                {
                    button[0].setTxt("Start");
                }
            }

            if(button[1].button(event)) // Wyjscie
                window->close();

            if(button[2].button(event)) // Opcje
            {
                if(isFullScreen)
                    return 0;
                else
                    return 1;
                //options(button, 3, mapScale(czy coś)); // przyciski, ilość, skala mapy, chyba tyle
            }

            if(button[3].button(event)) // <
            {

            }

            if(button[4].button(event)) // >
            {

            }
        }

        for(int i = 0; i < 5; ++i)
            button[i].draw();
    }

    return 3;
}

bool MainWin::start()
{
    loopTime = loopClock.getElapsedTime();
    loopClock.restart();

    window->display();
    window->clear(sf::Color(128, 128, 128));

    fps();

    return window->isOpen();
}

void MainWin::fps()
{
    static sf::Time second = sf::seconds(0);
    static int frapsPerSecond = 0;

    ++frapsPerSecond;
    second += loopTime;

    if(second > sf::seconds(1))
    {
        printf("Fps: %i\n", frapsPerSecond);
        frapsPerSecond = 0;

        for(; second > sf::seconds(1); second -= sf::seconds(1));
    }
}

void MainWin::setupButtons(Button *button, int amount)
{
    const int width = 200;
    const int height = 75;

    for(int i = 0; i < amount; ++i)
    {
        button[i].setDefCol(255, 64, 64);
        button[i].setHovCol(64, 255, 64);
        button[i].setActCol(64, 64, 255);
        button[i].setWin(*window);
        button[i].setTex("Images/button.png");
        button[i].setSiz(width, height);
        button[i].setPos(window->getSize().x * 0.99 - button[i].getSiz().x, 0);
        button[i].setTxtScl(0.4);
        button[i].setTxtMrg(45);

        sf::Text text;
        text.setFillColor(sf::Color(0, 0, 0));
        text.setOutlineColor(sf::Color(255, 255, 255));
        text.setOutlineThickness(1);

        button[i].setTxt(text);
    }

    // Dodatkowe ustawienia 3) "<" i 4) ">"
    button[3].setSiz(height * 0.75, height * 0.75); // <
    button[4].setSiz(height * 0.75, height * 0.75); // >

    button[3].setTxtMrg(20);
    button[4].setTxtMrg(20);

    // Tekst przycisków
    button[0].setTxt("Start");
    button[1].setTxt("Wyjscie");
    button[2].setTxt("Opcje");
    button[3].setTxt("<");
    button[4].setTxt(">");
    //button[].setTxt("");

    // Pozycje przycisków
    button[0].setPos(button[0].getPos().x, window->getSize().y * 0.02);
    button[1].setPos(button[1].getPos().x, window->getSize().y * 0.98 - height);
    button[2].setPos(button[2].getPos().x, window->getSize().y * 0.04 + height);
    button[3].setPos(button[3].getPos().x, window->getSize().y * 0.06 + height * 2);
    button[4].setPos(window->getSize().x * 0.99 - button[4].getSiz().x, button[3].getPos().y);
    //button[].setPos();

}




















