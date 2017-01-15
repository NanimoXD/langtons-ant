#include "MainWin.hpp"
#include "MainMgr.hpp"
#include "OptMgr.hpp"
#include "RenderMap.hpp"
#include "Fps.hpp"

void options(MainWin &mainWin)
{
    OptMgr optMgr(mainWin);

    while(mainWin.window->isOpen())
    {
        Fps()();

        switch(optMgr.main())
        {
        case -1:
            mainWin.window->close();
            break;
        case 10:
            if(!mainWin.isFullscreen())
            {
                mainWin.newWin(sf::Vector2u(), true);
                optMgr.placeButtons();
            }
            else
            {
                mainWin.newWin(sf::Vector2u(800, 600), false);
                optMgr.placeButtons();
            }
            break;
        case 190:
            return;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");

    MainWin mainWin(sf::Vector2u(800, 600));
    MainMgr mainMgr(mainWin);

    while(mainWin.window->isOpen())
    {
        Fps()();

        switch(mainMgr.main())
        {
        case -1:
            mainWin.window->close();
            break;
        case 20:
            options(mainWin);
            mainMgr.placeButtons();
            break;
        }
    }

    return EXIT_SUCCESS;
}
















