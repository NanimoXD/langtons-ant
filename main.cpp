#include "MainWin.hpp"
#include "MainMgr.hpp"
#include "OptMgr.hpp"
#include "Board2.hpp"
#include "BoardView.hpp"
#include "Ant2.hpp"
#include "Fps.hpp"

#include <iostream>

void options(OptMgr &optMgr, MainWin &mainWin, Ant2 &ant)
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

    Board2 board;
    board.addArea(20, Direction2::Right);
    board.addArea(20, Direction2::Down);

    Ant2 ant(board, 10, 10);

    Ant2::colors.push_back({sf::Color::White, Direction2::Left});
    Ant2::colors.push_back({sf::Color::Red, Direction2::Right});
    Ant2::colors.push_back({sf::Color::Green, Direction2::Right});
    Ant2::colors.push_back({sf::Color::Blue, Direction2::Right});
    Ant2::colors.push_back({sf::Color::Yellow, Direction2::Right});
    Ant2::colors.push_back({sf::Color::Magenta, Direction2::Left});
    Ant2::colors.push_back({sf::Color::Cyan, Direction2::Left});
    Ant2::colors.push_back({sf::Color(0, 128, 0), Direction2::Left});
    Ant2::colors.push_back({sf::Color(128, 0, 0), Direction2::Right});
    Ant2::colors.push_back({sf::Color(255, 0, 255), Direction2::Right});
    Ant2::colors.push_back({sf::Color(0, 255, 255), Direction2::Right});
    /*Ant2::colors.push_back({sf::Color(255, 255, 0), Direction2::Right});*/

    MainWin mainWin(sf::Vector2u(800, 600));
    MainMgr mainMgr(mainWin.window);
    OptMgr optMgr(mainWin);

    BoardView boardView;
    boardView.addArea(21, Direction2::Right);
    boardView.addArea(21, Direction2::Down);
    boardView.setCenter(sf::Vector2i(ant.getPos().x, ant.getPos().y));
    boardView.setWin(mainWin.window);
    boardView.setViewSiz(boardView.getSiz());
    boardView.setCol((sf::Vector2u)boardView.getCenter(), sf::Color(0, 0, 0));

    sf::Clock antClock;
    bool antMove = false;
    int antSpeed = 50;

    sf::Event event;
    while(mainWin.window->isOpen())
    {
        while(mainWin.window->pollEvent(event))
        {
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                    mainWin.window->close();
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
                antClock.restart();
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
                antClock.restart();
            }
        }

        for(sf::Time time = antClock.getElapsedTime(); antMove && time > sf::microseconds(antSpeed); time -= sf::microseconds(antSpeed))
        {
            antClock.restart();
            ant.nextStep();
            boardView.setCol(ant.getPos(), sf::Color::Black);
            boardView.setCol(sf::Vector2u(boardView.getCenter().x, boardView.getCenter().y), Ant2::colors[board.getCell(sf::Vector2u(boardView.getCenter().x, boardView.getCenter().y))].color);
            boardView.setCenter(sf::Vector2i(ant.getPos().x, ant.getPos().y));

            if(ant.getPos().x < 2)
            {
                board.addArea(10, Direction2::Left);
                boardView.addArea(10, Direction2::Left);
                boardView.setViewScl(boardView.getViewScl());
                boardView.setCenter(sf::Vector2i(boardView.getCenter().x + 10, boardView.getCenter().y));
                ant.setPos(ant.getPos().x + 10, ant.getPos().y);
            }

            if(ant.getPos().x > board.getSiz().x - 2)
            {
                board.addArea(10, Direction2::Right);
                boardView.addArea(10, Direction2::Right);
                boardView.setViewScl(boardView.getViewScl());
            }

            if(ant.getPos().y < 2)
            {
                board.addArea(10, Direction2::Up);
                boardView.addArea(10, Direction2::Up);
                boardView.setViewScl(boardView.getViewScl());
                boardView.setCenter(sf::Vector2i(boardView.getCenter().x, boardView.getCenter().y + 10));
                ant.setPos(ant.getPos().x, ant.getPos().y + 10);
            }

            if(ant.getPos().y > board.getSiz().y - 2)
            {
                board.addArea(10, Direction2::Down);
                boardView.addArea(10, Direction2::Down);
                boardView.setViewScl(boardView.getViewScl());
            }
        }

        // Przyciski
        switch(mainMgr.main())
        {
        case 10:
            antMove = true;
            antClock.restart();
            break;
        case 11:
            antMove = false;
            break;
        case 20:
            board.clear();
            board.addArea(21, Direction2::Right);
            board.addArea(21, Direction2::Down);

            ant.setPos(10, 10);
            ant.setDir(Direction2::Up);

            boardView.newBoard();
            boardView.addArea(20, Direction2::Right);
            boardView.addArea(20, Direction2::Down);
            boardView.setCenter(sf::Vector2i(ant.getPos().x, ant.getPos().y));
            boardView.setViewSiz(boardView.getSiz());
            boardView.setCol((sf::Vector2u)boardView.getCenter(), sf::Color(0, 0, 0));
            break;
        case 30:
            options(optMgr, mainWin, ant);
            boardView.update();
            mainMgr.placeButtons();
            antClock.restart();
            break;
        case 40:
            boardView.setViewScl(boardView.getViewScl() - 0.05);
            break;
        case 50:
            boardView.setViewScl(boardView.getViewScl() + 0.05);
            break;
        case 60:
            mainWin.window->close();
            break;
        }


        boardView.draw();

        mainWin.window->display();
        mainWin.window->clear(sf::Color(128, 128, 128));

        Fps()();
    }

    return EXIT_SUCCESS;
}
















