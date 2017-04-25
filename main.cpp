#include "MainWin.hpp"
#include "MainMgr.hpp"
#include "OptMgr.hpp"
#include "Board2.hpp"
#include "BoardView.hpp"
#include "Ant2.hpp"
#include "Fps.hpp"

#include <iostream>

void options(OptMgr &optMgr, MainWin &mainWin)
{
    for(uint32_t i = 0; i < Ant2::colors.size(); ++i)
    {
        if(Ant2::colors[i].active == true)
        {
            switch(Ant2::colors[i].direction)
            {
            case Direction2::Right:
                optMgr.setStrId(i + 6, 2);
                break;
            case Direction2::Left:
                optMgr.setStrId(i + 6, 3);
                break;
            case Direction2::Up:
                optMgr.setStrId(i + 6, 4);
                break;
            case Direction2::Down:
                optMgr.setStrId(i + 6, 5);
                break;
            }
        }
        else
            optMgr.setStrId(i + 6, 1);
    }

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
        case 30:
            for(uint32_t i = 6; i < 18; ++i)
                optMgr.setStrId(i, 1);
            break;
        case 190:
            {
                bool ok = false;

                for(uint32_t i = 0; i < Ant2::colors.size(); ++i)
                {
                    switch(optMgr.getStrId(i + 6))
                    {
                    case 1:
                        Ant2::colors[i].active = false;
                        break;
                    case 2:
                        ok = true;
                        Ant2::colors[i].active = true;
                        Ant2::colors[i].direction = Direction2::Right;
                        break;
                    case 3:
                        ok = true;
                        Ant2::colors[i].active = true;
                        Ant2::colors[i].direction = Direction2::Left;
                        break;
                    case 4:
                        ok = true;
                        Ant2::colors[i].active = true;
                        Ant2::colors[i].direction = Direction2::Up;
                        break;
                    case 5:
                        ok = true;
                        Ant2::colors[i].active = true;
                        Ant2::colors[i].direction = Direction2::Down;
                        break;
                    }
                }
                if(ok) return;
                else break;
            }
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

    Ant2::colors.push_back({sf::Color(255, 32, 32), Direction2::Left, true});
    Ant2::colors.push_back({sf::Color(255, 255, 32), Direction2::Right, true});
    Ant2::colors.push_back({sf::Color(32, 255, 32), Direction2::Right, false});
    Ant2::colors.push_back({sf::Color(32, 255, 255), Direction2::Right, false});
    Ant2::colors.push_back({sf::Color(32, 32, 255), Direction2::Right, false});
    Ant2::colors.push_back({sf::Color(255, 32, 255), Direction2::Right, false});

    Ant2::colors.push_back({sf::Color(255, 140, 32), Direction2::Right, false});
    Ant2::colors.push_back({sf::Color(140, 255, 32), Direction2::Right, false});
    Ant2::colors.push_back({sf::Color(32, 255, 140), Direction2::Right, false});
    Ant2::colors.push_back({sf::Color(32, 140, 255), Direction2::Right, false});
    Ant2::colors.push_back({sf::Color(140, 32, 255), Direction2::Right, false});
    Ant2::colors.push_back({sf::Color(255, 32, 140), Direction2::Right, false});

    MainWin mainWin(sf::Vector2u(800, 600));
    MainMgr mainMgr(mainWin.window);
    OptMgr optMgr(mainWin);

    BoardView boardView;
    boardView.addArea(21, Direction2::Right);
    boardView.addArea(21, Direction2::Down);
    boardView.setWin(mainWin.window);
    boardView.setCenter(sf::Vector2i(ant.getPos().x, ant.getPos().y));
    boardView.setViewSiz(boardView.getSiz());
    boardView.setCol(ant.getPos(), sf::Color(0, 0, 0));

    sf::Clock antClock;
    bool antMove = false;
    uint32_t antSpeed = 1;
    uint32_t antStep = 0;

    mainMgr.setSpeed(antSpeed);
    mainMgr.setStep(antStep);

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
                mainMgr.update();
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

        for(sf::Time time = antClock.getElapsedTime() > sf::seconds(2) ? sf::seconds(2) : antClock.getElapsedTime(); antMove && time > sf::microseconds(1 << (21 - antSpeed)); time -= sf::microseconds(1 << (21 - antSpeed)), mainMgr.setStep(++antStep))
        {
            antClock.restart();
            ant.nextStep();
            boardView.setCenter(sf::Vector2i(ant.getPos().x, ant.getPos().y));
            boardView.setCol(ant.getPos(), sf::Color::Black);
            boardView.setCol(ant.getShadow(), Ant2::colors[board.getCell(ant.getShadow())].color);

            if(ant.getPos().x < 2)
            {
                board.addArea(10, Direction2::Left);
                boardView.addArea(10, Direction2::Left);

                boardView.setViewScl(boardView.getViewScl());

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
            ant.setShadow(10, 10);
            ant.setDir(Direction2::Up);

            boardView.newBoard();
            boardView.addArea(20, Direction2::Right);
            boardView.addArea(20, Direction2::Down);
            boardView.setViewSiz(boardView.getSiz());
            boardView.setCenter(sf::Vector2i(ant.getPos().x, ant.getPos().y));
            boardView.setCol(ant.getPos(), sf::Color(0, 0, 0));
            break;
        case 30:
            options(optMgr, mainWin);
            boardView.update();
            mainMgr.update();
            antClock.restart();
            break;
        case 40:
            if(--antSpeed < 1) ++antSpeed;
            mainMgr.setSpeed(antSpeed);
            break;
        case 50:
            if(++antSpeed > 16) --antSpeed;
            mainMgr.setSpeed(antSpeed);
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
















