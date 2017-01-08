#include <SFML/System.hpp>

#include "MainWin.hpp"

int main()
{
    setlocale(LC_ALL, "");

    int ret = 0;

    do
    {
        MainWin mainWin(sf::Vector2u(800, 600), ret);
        ret = mainWin.main();
    }while(ret == 0 || ret == 1);

    return ret;
}
















