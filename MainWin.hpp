#ifndef MainWin_hpp
#define MainWin_hpp

class MainWin:
    public Veque
{
    sf::Time time;                              // Przechowuje czas od ostatniego uruchomienia start()
    sf::Clock clo;                              // Liczy czas od ostatniego uruchomienia start()

    sf::RenderWindow window;                    // Okno :p

    void events(sf::Event &event);              // Metoda do eventów

public:
    MainWin(sf::Vector2f winScale);             // Konstruktor. winScale = skala okna wzglêdem ekranu
                                                // Domyœlnie 0.5 i 0.75 bo czemu nie XD :p

    const sf::Vector2f winSize;                 // Wielkoœæ okna w pixelach

    bool start();                               // Metoda robi¹ca wszystko co trzeba

    sf::Time clock();                           // Zwraca time
};

MainWin::MainWin(sf::Vector2f winScale = sf::Vector2f(0.5, 0.75)):
    Veque       (),
    winSize     (sf::VideoMode::getDesktopMode().width * winScale.x, sf::VideoMode::getDesktopMode().height * winScale.y)
{
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

        sf::Image icon;
        if(icon.loadFromFile("Images/icon.png"))
            window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    }

    time = clo.getElapsedTime();
    clo.restart();

    window.clear(sf::Color::Black);
    draw(window);
    window.display();

    sf::Event event;
    while(window.pollEvent(event)){events(event);}

    return window.isOpen();
}

sf::Time MainWin::clock()
{
    return time;
}

#endif // MainWin_hpp













