#include "Fps.hpp"

sf::Clock Fps::clock;
unsigned short Fps::fraps;
unsigned short Fps::amount;

void Fps::operator()()
{
    if(clock.getElapsedTime() >= sf::seconds(1))
    {
        printf("\nLog: %5i\tFps: %i\t", amount, fraps);
        clock.restart();
        fraps = 0;
        ++amount;
        return;
    }

    ++fraps;
}
