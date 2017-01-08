#ifndef MainWin_hpp
#define MainWin_hpp

#include "Button.hpp"

#include <SFML/Graphics.hpp>

class MainWin
{
public:
    MainWin(sf::Vector2u winSize, bool fullScreen); // Konstruktor
    ~MainWin();                                     // Destruktor

    int main();                                     // Główna funkcja

private:
    sf::RenderWindow *window;                       // Okno :p

    sf::Event event;                                // Event :D

    sf::Time loopTime;                              // Czas od ostatniego wywołania start()
    sf::Clock loopClock;                            // Liczy czas od ostatniego wywołania start()

    bool isFullScreen;                              // Prawda jeśli aktualnie okno jest w trybie pełnoekranowym

    bool start();                                   // Czyszczenie sceny, reset zegara, liczenie FPS

    void fps();                                     // Funkcja licząca i wyświetlająca FPS

    void setupButtons(Button *buttons, int amount); // Wszystkie ustawienia związane z wyglądem przycisków
};
#endif // MainWin_hpp





















