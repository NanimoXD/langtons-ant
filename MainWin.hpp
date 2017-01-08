#ifndef MainWin_hpp
#define MainWin_hpp

#include "Button.hpp"

#include <SFML/Graphics.hpp>

#include <cstdio>

class MainWin
{
public:
    MainWin(sf::Vector2u winSize, bool fullScreen); // Konstruktor
    ~MainWin();                                     // Destruktor

    sf::RenderWindow *window;                       // Okno :p

    int main();                                     /*  Główna funkcja:
                                                     *  0) Nic
                                                     *  1) Start
                                                     *  2) Stop
                                                     *  3) Opcje
                                                     *  4) <
                                                     *  5) >
                                                     *  6) Wyjście
                                                     */

private:
    sf::Event event;                                // Event :D

    sf::Time loopTime;                              // Czas od ostatniego wywołania start()
    sf::Clock loopClock;                            // Liczy czas od ostatniego wywołania start()

    Button button[5];                               // Przyciski ^^

    bool start();                                   // Czyszczenie sceny, reset zegara, liczenie FPS

    void fps();                                     // Funkcja licząca i wyświetlająca FPS

    void setupButtons(Button *buttons, int amount); // Wszystkie ustawienia związane z wyglądem przycisków
};
#endif // MainWin_hpp





















