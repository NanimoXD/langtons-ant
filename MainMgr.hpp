#ifndef MainMgr_hpp
#define MainMgr_hpp

#include "Button.hpp"

#include <sstream>

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
                                                     *  40) -
                                                     *  50) +
                                                     *  60) Wyjście
                                                     */

    void update();                                  // Ustawia menu na właściwym miejscu

    void setSpeed(uint32_t speed);                  // Ustawia prędkość

    void setStep(uint32_t step);                    // Resetuje ilość kroków

private:
    sf::RenderWindow *window;                       // Okno :p

    static const char amount = 6;                   // Ilość przycisków

    static const int width = 200;                   // Szerokość przycisków
    static const int height = 75;                   // Wysokość przycisków

    Button button[amount];                          // Przyciski ^^

    sf::Font font;                                  // Czcionka dla tekstów

    sf::Text speedText;                             // Wyświetlanie prędkości obiektów

    sf::Text stepText;                              // Wyświetlanie ilości kroków

    void setup();                                   // Wszystkie ustawienia związane z wyglądem menu
};

#endif // MainMgr_hpp















