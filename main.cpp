#include "MainWin.hpp"
#include "MainMgr.hpp"
#include "OptMgr.hpp"
#include "BoardView.hpp"
#include "Fps.hpp"

#include <cstdlib>

void options(OptMgr &optMgr, MainWin &mainWin)
{
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

        mainWin.window->display();
        mainWin.window->clear(sf::Color(128, 128, 128));
    }
}

int main()
{
    setlocale(LC_ALL, "");
    srand(time(0));

    MainWin mainWin(sf::Vector2u(800, 600));
    MainMgr mainMgr(mainWin.window);
    OptMgr optMgr(mainWin);

    BoardView boardView;
    boardView.addArea(200, Direction::Right);
    boardView.addArea(200, Direction::Down);
    boardView.setCenter(sf::Vector2i(100, 100));
    boardView.setWin(mainWin.window);
    boardView.setViewSiz(boardView.getSiz());
    boardView.setCol((sf::Vector2u)boardView.getCenter(), sf::Color(0, 0, 0));

    sf::Event event;
    while(mainWin.window->isOpen())
    {
        while(mainWin.window->pollEvent(event))
        {
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                    mainWin.window->close();
                else if(event.key.code == sf::Keyboard::Up)
                    boardView.setCenter(sf::Vector2i(boardView.getCenter().x, boardView.getCenter().y - 1));
                else if(event.key.code == sf::Keyboard::Down)
                    boardView.setCenter(sf::Vector2i(boardView.getCenter().x, boardView.getCenter().y + 1));
                else if(event.key.code == sf::Keyboard::Left)
                    boardView.setCenter(sf::Vector2i(boardView.getCenter().x - 1, boardView.getCenter().y));
                else if(event.key.code == sf::Keyboard::Right)
                    boardView.setCenter(sf::Vector2i(boardView.getCenter().x + 1, boardView.getCenter().y));

                boardView.setCol((sf::Vector2u)boardView.getCenter(), sf::Color(0, 0, 0));
            }
            else if(event.type == sf::Event::MouseWheelScrolled)
            {
                boardView.setViewScl(boardView.getViewScl() - event.mouseWheelScroll.delta / 50);
            }
            else if(event.type == sf::Event::Resized)
            {
                mainWin.newWin(sf::Vector2u(event.size.width, event.size.height));
                boardView.update();
                mainMgr.placeButtons();
                optMgr.placeButtons();
            }
            else if(event.type == sf::Event::Closed)
            {
                mainWin.window->close();
            }
            else if(event.type == sf::Event::LostFocus)
            {
                do
                {
                    mainWin.window->waitEvent(event);
                }while(event.type != sf::Event::GainedFocus);
            }
        }



        Fps()();

        boardView.draw();

        // Przyciski
        switch(mainMgr.main())
        {
        case 10:
            for(int i = 0; i < boardView.getSiz().x; ++i)
            {
                for(int j = 0; j < boardView.getSiz().y; j++)
                    boardView.setCol(sf::Vector2u(i, j), sf::Color(rand() % 255, rand() % 255, rand() % 255));
            }
            break;
        case 11:
            for(int i = 0; i < boardView.getSiz().x; ++i)
            {
                for(int j = 0; j < boardView.getSiz().y; j++)
                    boardView.setCol(sf::Vector2u(i, j), boardView.getDefCol());
            }
            break;
        case 20:
            options(optMgr, mainWin);
            boardView.update();
            mainMgr.placeButtons();
            break;
        case 30:
            //boardView.setViewSiz(sf::Vector2i(boardView.getViewSiz().x - 2, boardView.getViewSiz().y - 2));
            break;
        case 40:
            //boardView.setViewSiz(sf::Vector2i(boardView.getViewSiz().x + 2, boardView.getViewSiz().y + 2));
            break;
        case 50:
            mainWin.window->close();
            break;
        }

        mainWin.window->display();
        mainWin.window->clear(sf::Color(128, 128, 128));
    }

    return EXIT_SUCCESS;
}
















