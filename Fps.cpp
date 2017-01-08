#include "Fps.hpp"

unsigned int Fps::fraps;
sf::Clock Fps::clock;

void Fps::operator()()
{
    ++fraps;

    if(clock.getElapsedTime() > sf::seconds(1))
    {
        printf("Fps: %i\n", fraps);
        clock.restart();
        fraps = 0;
    }
}
