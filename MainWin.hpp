#ifndef MainWin_hpp
#define MainWin_hpp

#include "Veque.hpp"
#include "Button.hpp"
#include "Ant.hpp"

#include <SFML/Graphics.hpp>

#include <queue>

class MainWin
{
public:
    MainWin(sf::Vector2f winSize);                  // Konstruktor
    ~MainWin();                                     // Destruktor

    int main();                                     // Główna funkcja

private:
    sf::RenderWindow *window;                       // Okno :p

    std::queue<void *>rubbish;                      // Śmieci do zniszczenia w destruktorze

    sf::Event event;                                // Event :D

    sf::Time time;                                  // Czas od ostatniego wywołania start()
    sf::Clock clock;                                // Liczy czas od ostatniego wywołania start()

    bool start();                                   // Czyszczenie sceny i reset zegara

    void createMap(Veque &map);                     // Tworzy szachownice
};
#endif // MainWin_hpp





















