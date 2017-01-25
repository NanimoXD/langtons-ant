#include "MainWin.hpp"
#include "MainMgr.hpp"
#include "OptMgr.hpp"
#include "BoardView.hpp"
#include "Fps.hpp"

void options(MainWin &mainWin)
{
    OptMgr optMgr(mainWin);

    while(mainWin.window->isOpen())
    {
        Fps()();

        MgrRet ret = optMgr.main();

        if(ret.close)
            mainWin.window->close();

        if(ret.resize)
            optMgr.placeButtons();

        switch(ret.id)
        {
        case 10:
            if(!mainWin.isFullscreen())
                mainWin.newWin(sf::Vector2u(), true);
            else
                mainWin.newWin(sf::Vector2u(800, 600), false);

            optMgr.placeButtons();
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

    BoardView boardView;
    boardView.setMapSiz(sf::Vector2u(100, 100));
    boardView.setCol(sf::Vector2u(1, 1), sf::Color(255, 0, 0));
    boardView.setView(sf::IntRect(0, 0, boardView.getMapSiz().x, boardView.getMapSiz().y));
    boardView.setWin(mainWin.window);

    while(mainWin.window->isOpen())
    {
        Fps()();

        boardView.draw();

        MgrRet ret = mainMgr.main();

        if(ret.close)
            mainWin.window->close();

        if(ret.resize)
        {
            boardView.update();
            mainMgr.placeButtons();
        }

        switch(ret.id)
        {
        case 20:
            options(mainWin);
            boardView.update();
            mainMgr.placeButtons();
            break;
        }
    }

    return EXIT_SUCCESS;
}
















