#include <SFML/System.hpp>

#include "MainWin.hpp"
#include "MainMgr.hpp"
#include "Fps.hpp"

int main()
{
    setlocale(LC_ALL, "");

    MainWin mainWin(sf::Vector2u(800, 600), false);
    MainMgr mainMgr(mainWin.window);

    for(int mainRet = 0; ; mainRet = mainMgr.main())
    {
        Fps()();

        if(mainRet == 3)
        {
            mainWin.newWin(sf::Vector2u(800, 600), !mainWin.isFullscreen());
            mainMgr.placeButtons();
        }

        if(mainRet == 6 || mainRet == 404)
        {
            mainWin.window->close();
            break;
        }
    }

    return EXIT_SUCCESS;
}
















