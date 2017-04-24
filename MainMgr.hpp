#ifndef MainMgr_hpp
#define MainMgr_hpp

#include "Button.hpp"

class MainMgr
{
public:
    MainMgr(sf::RenderWindow *_window);          // Konstruktor

    int main();                                  /*  Główna funkcja:
                                                     *  00) Nic
                                                     *  10) Start
                                                     *  11) Stop
                                                     *  20) Stop
                                                     *  30) Opcje
                                                     *  40) <
                                                     *  50) >
                                                     *  60) Wyjście
                                                     */

    void placeButtons();                            // Ustawia przyciski na właściwym miejscu

private:
    sf::RenderWindow *window;                       // Okno :p

    static const char amount = 6;                   // Ilość przycisków

    static const int width = 200;                   // Szerokość przycisków
    static const int height = 75;                   // Wysokość przycisków

    Button button[amount];                          // Przyciski ^^

    void setupButtons();                            // Wszystkie ustawienia związane z wyglądem przycisków
};

#endif // MainMgr_hpp















