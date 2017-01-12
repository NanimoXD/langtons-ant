#include "Fps.hpp"

unsigned int Fps::fraps;
sf::Clock Fps::clock;

void Fps::operator()()
{
    if(clock.getElapsedTime() >= sf::seconds(1))
    {
        printf("\nFps: %i\t", fraps);
        clock.restart();
        fraps = 0;
        return;
    }

    ++fraps;
}
