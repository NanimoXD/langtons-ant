#ifndef MainMgr_hpp
#define MainMgr_hpp

#include "Button.hpp"

#include <SFML/Graphics.hpp>

class MainMgr
{
public:
    MainMgr(sf::RenderWindow *window);              // Konstruktor

    int main();                                     /*  Główna funkcja:
                                                     *  0) Nic
                                                     *  1) Start
                                                     *  2) Stop
                                                     *  3) Opcje
                                                     *  4) <
                                                     *  5) >
                                                     *  6) Wyjście
                                                     */

    void placeButtons();                            // Ustawia przyciski na właściwym miejscu

private:
    sf::Event event;                                // Event :D

    sf::RenderWindow *window;                       // Okno :p

    static const char amount = 5;                   // Ilość przycisków

    static const int width = 200;                   // Szerokość przycisków
    static const int height = 75;                   // Wysokość przycisków

    Button button[amount];                          // Przyciski ^^

    void setupButtons();                            // Wszystkie ustawienia związane z wyglądem przycisków
};

#endif // MainMgr_hpp
