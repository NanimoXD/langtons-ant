#ifndef Fps_hpp
#define Fps_hpp

#include <SFML/System.hpp>

class Fps
{
public:
    void operator()();              // Zlicza fps i wyświetla ich ilość co sekundę

private:
    static sf::Clock clock;         // Zegar odliczający sekunde

    static unsigned short fraps;    // Licznik fps

    static unsigned short amount;   // Licznik logów
};

#endif // Fps_hpp
















