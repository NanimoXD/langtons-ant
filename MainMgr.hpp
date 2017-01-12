#ifndef MainMgr_hpp
#define MainMgr_hpp

#include "MainWin.hpp"
#include "Button.hpp"

class MainMgr
{
public:
    MainMgr(MainWin &_mainWin);                     // Konstruktor

    int main();                                     /*  Główna funkcja:
                                                     *  -1) Wyjście
                                                     *  00) Nic
                                                     *  10) Start
                                                     *  11) Stop
                                                     *  20) Opcje
                                                     *  30) <
                                                     *  40) >
                                                     */

    void placeButtons();                            // Ustawia przyciski na właściwym miejscu

private:
    sf::Event event;                                // Event :D

    MainWin mainWin;                                // Okno :p

    static const char amount = 5;                   // Ilość przycisków

    static const int width = 200;                   // Szerokość przycisków
    static const int height = 75;                   // Wysokość przycisków

    Button button[amount];                          // Przyciski ^^

    void setupButtons();                            // Wszystkie ustawienia związane z wyglądem przycisków
};

#endif // MainMgr_hpp
