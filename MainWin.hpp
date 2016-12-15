#ifndef MainWin_hpp
#define MainWin_hpp

namespace jk
{
    class MainWin:
        public Veque
    {
        sf::Time time;
        sf::Clock clo;

        sf::RenderWindow window;

        void events(sf::Event &event);

    public:
        MainWin(sf::Vector2f winScale);

        const sf::Vector2f winSize;

        bool start();

        sf::Time clock();
    };

    MainWin::MainWin(sf::Vector2f winScale = sf::Vector2f(2, 1.5)):
        Veque       (),
        winSize     (sf::VideoMode::getDesktopMode().width / winScale.x, sf::VideoMode::getDesktopMode().height / winScale.y)
    {
        clo.restart();
    }

    bool MainWin::start()
    {
        if(!window.isOpen())
        {
            window.create(sf::VideoMode(winSize.x, winSize.y, sf::VideoMode::getDesktopMode().bitsPerPixel), "Ant XD", sf::Style::Close);
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
}

#endif // MainWin_hpp













