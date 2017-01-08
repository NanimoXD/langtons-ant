#ifndef Fps_hpp
#define Fps_hpp

#include <SFML/System.hpp>

class Fps
{
    static sf::Clock clock;     // Zegar odliczający sekunde

    static unsigned int fraps;  // Licznik fps

public:
    void operator()();            // Zlicza fps i wyświetla ich ilość co sekundę
};

#endif // Fps_hpp
















