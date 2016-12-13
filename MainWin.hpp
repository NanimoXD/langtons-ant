#ifndef MainWin_hpp
#define MainWin_hpp

namespace jk
{
    class MainWin
    {
        void events(sf::Event &event);
        void display();

    public:
        MainWin(sf::Vector2f winScale);

        const sf::Vector2f winSize;

        sf::RenderWindow window;

        jk::Veque sprites;

        bool start();
    };

    MainWin::MainWin(sf::Vector2f winScale = sf::Vector2f(2, 1.5)):
        winSize     (sf::VideoMode::getDesktopMode().width / winScale.x, sf::VideoMode::getDesktopMode().height / winScale.y){}

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

        display();

        sf::Event event;
        while(window.pollEvent(event)){events(event);}

        return window.isOpen();
    }
}

#endif // MainWin_hpp













