#ifndef MainWin_hpp
#define MainWin_hpp

#include "Veque.hpp"
#include "Button.hpp"
#include "Ant.hpp"

#include <SFML/Config.hpp>

class MainWin:
    public Veque
{
    sf::Time time;                                  // Przechowuje czas od ostatniego wywołania start()
    sf::Clock clo;                                  // Liczy czas od ostatniego wywołania start()

    sf::RenderWindow window;                        // Okno :p

    void events(sf::Event &event);                  // Metoda do eventów

    Button button;                                  // Testowy przycisk :D

    bool qwer;                                      // Taka pierdoła żeby kontrolować zmiane kolorków :p

public:
    MainWin(sf::Vector2f winScale);                 // Konstruktor. winScale = skala okna względem ekranu
                                                    // Domyślnie 0.5 i 0.75 bo czemu nie XD :p

    const sf::Vector2f winSize;                     // Wielkość okna w pixelach

    bool start();                                   // Metoda robiąca wszystko co trzeba

    sf::Time clock();                               // Zwraca time

    void drawSpr(sf::Sprite spr);                   // Rysuje Sprita :p
};

MainWin::MainWin(sf::Vector2f winScale = sf::Vector2f(0.5, 0.75)):
    Veque       (),
    button      (),
    qwer        (true),
    winSize     (sf::VideoMode::getDesktopMode().width * winScale.x, sf::VideoMode::getDesktopMode().height * winScale.y)
{
    button.setDefCol(255, 255, 255);
    button.setHovCol(0, 255, 255, 192);
    button.setActCol(0, 255, 255);
    button.setWin(window);
    button.setTex("Images/background.jpg");
    button.setSiz(300, 100);
    button.setPos(winSize.x / 2 - 150, winSize.y / 2 - 50);

    sf::Text text;
    text.setFillColor(sf::Color(0, 0, 0));
    text.setString("Lol no witam :D");
    button.setTxt(text);

    clo.restart();
}

bool MainWin::start()
{
    if(!window.isOpen())
    {
        window.create(sf::VideoMode(winSize.x, winSize.y, sf::VideoMode::getDesktopMode().bitsPerPixel), "Ant XD", sf::Style::Close);
        window.setFramerateLimit(60);
        window.clear(sf::Color::Black);
        window.display();

/* Przynajmniej do czasu naprawienia błędu #1168 (https://github.com/SFML/SFML/issues/1168) */
#ifndef SFML_SYSTEM_LINUX
        sf::Image icon;
        if(icon.loadFromFile("Images/icon.png"))
            window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
#endif

        for(int i = qwer; i < size(); i += 2)
            get(i)->setColor(sf::Color(0, 255, 255));

        for(int i = !qwer; i < size(); i += 2)
            get(i)->setColor(sf::Color(0, 0, 255));

        qwer = !qwer;
    }

    sf::Event event;
    while(window.pollEvent(event))
    {
        events(event);

        // Przycisk przycisk :D
        // To wszystko co potrzeba :p
        // Trzeba jednak pamiętać że funkcja zawiera rysowanie przycisku :p
        if(button.button(event))
        {
            for(int i = qwer; i < size(); i += 2)
                get(i)->setColor(sf::Color(0, 255, 255));

            for(int i = !qwer; i < size(); i += 2)
                get(i)->setColor(sf::Color(0, 0, 255));

            qwer = !qwer;
        }
    }

    time = clo.getElapsedTime();
    clo.restart();

    button.draw();
    window.display();
    window.clear(sf::Color::Black);
    draw(window);

    return window.isOpen();
}

sf::Time MainWin::clock()
{
    return time;
}

void MainWin::drawSpr(sf::Sprite spr)
{
    window.draw(spr);
}

#endif // MainWin_hpp










