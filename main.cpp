#include "MainWin.hpp"
#include "MainMgr.hpp"
#include "OptMgr.hpp"
#include "BoardView.hpp"
#include "Fps.hpp"

#include <cstdlib>

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
    srand(time(0));

    MainWin mainWin(sf::Vector2u(800, 600));
    MainMgr mainMgr(mainWin);

    BoardView boardView;
    boardView.setWin(mainWin.window);
    boardView.addArea(1000, Direction::Right);
    boardView.addArea(1000, Direction::Down);
    boardView.setView(sf::IntRect(0, 0, boardView.getMapSiz().x, boardView.getMapSiz().y));

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
        case 10:
            for(int i = 0; i < 1000; ++i)
            {
                for(int j = 0; j < 1000; j++)
                    boardView.setCol(sf::Vector2u(i, j), sf::Color(rand() % 255, rand() % 255, rand() % 255));
            }
            break;
        case 11:
            for(int i = 0; i < 1000; ++i)
            {
                for(int j = 0; j < 1000; j++)
                    boardView.setCol(sf::Vector2u(i, j), boardView.getDefCol());
            }
            break;
        case 20:
            options(mainWin);
            boardView.update();
            mainMgr.placeButtons();
            break;
        }
    }

    printf("Lol no witam XD");

    return EXIT_SUCCESS;
}
















