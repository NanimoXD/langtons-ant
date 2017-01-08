#include <SFML/System.hpp>

#include "MainWin.hpp"

int main()
{
    setlocale(LC_ALL, "");

    bool winFullscr = false;

    MainWin *mainWin = new MainWin(sf::Vector2u(800, 600), winFullscr);

    for(int mainRet = 0; ; mainRet = mainWin->main())
    {
        if(mainRet == 3)
        {
            delete mainWin;
            winFullscr = !winFullscr;
            mainWin = new MainWin(sf::Vector2u(800, 600), winFullscr);
        }

        if(mainRet == 6 || mainRet == 404)
        {
            delete mainWin;
            break;
        }
    }

    return EXIT_SUCCESS;
}
















