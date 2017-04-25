#ifndef OptMgr_hpp
#define OptMgr_hpp

#include "MainWin.hpp"
#include "Button.hpp"
#include "MgrRet.hpp"

#include <cstdio>

class OptMgr
{
public:
    OptMgr(MainWin &mainWin);                       // Konstruktor

    MgrRet main();                                  /*  Główna funkcja:
                                                     *  00) Nic
                                                     *  10) Pełny ekran
                                                     *  20) Przycisk 2
                                                     *  30) Przycisk 3
                                                     *  40) Przycisk 4
                                                     *  50) Przycisk 5
                                                     *  60) Przycisk 6
                                                     *  70) Przycisk 7
                                                     *  80) Przycisk 8
                                                     *  90) Przycisk 9
                                                     *  100) Przycisk 10
                                                     *  110) Przycisk 11
                                                     *  120) Przycisk 12
                                                     *  130) Przycisk 13
                                                     *  140) Przycisk 14
                                                     *  150) Przycisk 15
                                                     *  160) Przycisk 16
                                                     *  170) Przycisk 17
                                                     *  180) Przycisk 18
                                                     *  190) Powrót
                                                     */

    void placeButtons();                            // Ustawia przyciski na właściwym miejscu

    void setStrId(uint8_t num, short id);           // Zmienia text przycisku na następny i zwraca jego numer

    // Pobieranie wartości:
    // ----------------------------------------------

    uint8_t     getAmount()             {return amount;}

    short       getStrId(uint8_t num)   {return num < amount ? button[num].getTxtId() : 0;}

private:
    sf::Event event;                                // Event :D

    MainWin mainWin;                                // Okno :p

    static const uint8_t amount = 19;               // Ilość przycisków

    Button button[amount];                          // Przyciski ^^

    static const int width = 200;                   // Szerokość przycisków
    static const int height = 75;                   // Wysokość przycisków

    void setupButtons();                            // Wszystkie ustawienia związane z wyglądem przycisków
};

#endif // OptMgr_hpp























