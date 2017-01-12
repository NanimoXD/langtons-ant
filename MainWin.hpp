#ifndef MainWin_hpp
#define MainWin_hpp

#include <SFML/Graphics.hpp>

class MainWin
{
public:
    MainWin(sf::Vector2u winSiz, bool _fullscreen = false);     // Konstruktor, wywołuje newWin()

    sf::RenderWindow *window;                                   // Okno

    void newWin(sf::Vector2u winSiz, bool _fullscreen = false); // Usuwa stare i tworzy nowe okno

    bool isFullscreen();                                        // Jeżeli okno jest w trybie pełnoekranowym zwraca prawde

private:
    bool fullscreen;                                            // Przechowywuje wartość którą zwraca funkcja isFullscreen()
};

#endif // MainWin_hpp





















