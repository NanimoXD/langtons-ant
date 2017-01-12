#include "MainMgr.hpp"

#include <cstdio>

MainMgr::MainMgr(MainWin &_mainWin):
    mainWin      (_mainWin)
{
    setupButtons();             /*  0) Start / Stop
                                 *  1) Opcje
                                 *  2) <
                                 *  3) >
                                 *  4) Wyjście
                                 */
}

int MainMgr::main()
{
    int ret = 0;

    while(mainWin.window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            ret = -1;
        else if(event.type == sf::Event::Resized)
        {
            sf::FloatRect view(0, 0, event.size.width, event.size.height);

            if(view.width < 800) mainWin.window->setSize(sf::Vector2u(800, view.height));
            if(view.height < 600) mainWin.window->setSize(sf::Vector2u(view.width, 600));

            mainWin.window->setView(sf::View(view));
            placeButtons();
        }
        else if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Escape)
                ret = -1;
        }

        // Przyciski ---------------------------------------

        if(button[0].button(event))         // Start / Stop
        {
            if(button[0].getTxt().getString() == "Start")
            {
                button[0].setTxt("Stop");
                ret = 10;
            }
            else
            {
                button[0].setTxt("Start");
                ret = 11;
            }
        }

        if(button[1].button(event))    // Opcje
            ret = 20;


        if(button[2].button(event))    // <
            ret = 30;


        if(button[3].button(event))    // >
            ret = 40;


        if(button[4].button(event))    // Wyjście
            ret = -1;
    }

    for(int i = 0; i < 5; ++i)
        button[i].draw();

    mainWin.window->display();
    mainWin.window->clear(sf::Color(128, 128, 128));

    if(ret) printf("MainMgr: %2i\t", ret);

    return ret;
}

void MainMgr::placeButtons()
{
    button[0].setPos(mainWin.window->getSize().x * 0.99 - width, mainWin.window->getSize().y * 0.02);               // Start / Stop
    button[1].setPos(mainWin.window->getSize().x * 0.99 - width, mainWin.window->getSize().y * (0.17));             // Opcje
    button[2].setPos(mainWin.window->getSize().x * 0.99 - width, mainWin.window->getSize().y * (0.32));             // <
    button[3].setPos(mainWin.window->getSize().x * 0.99 - height * 0.75, mainWin.window->getSize().y * (0.32));     // >
    button[4].setPos(mainWin.window->getSize().x * 0.99 - width, mainWin.window->getSize().y * 0.98 - height);      // Wyjście
}

void MainMgr::setupButtons()
{
    button[0].setDefCol(255, 64, 64);
    button[0].setHovCol(64, 255, 64);
    button[0].setActCol(64, 64, 255);
    button[0].setWin(*mainWin.window);
    button[0].setTex("Images/button.png");
    button[0].setSiz(width, height);
    button[0].setTxtScl(0.4);
    button[0].setTxtMrg(45);

    sf::Text text;
    text.setFillColor(sf::Color(0, 0, 0));
    text.setOutlineColor(sf::Color(255, 255, 255));
    text.setOutlineThickness(1);

    button[0].setTxt(text);

    for(int i = 1; i < amount; ++i)
        button[i] = button[0];

    // Dodatkowe ustawienia 3) "<" i 4) ">"
    button[2].setSiz(height * 0.75, height * 0.75); // <
    button[3].setSiz(height * 0.75, height * 0.75); // >

    button[2].setTxtMrg(20);
    button[3].setTxtMrg(20);

    // Tekst przycisków
    button[0].setTxt("Start");
    button[1].setTxt("Opcje");
    button[2].setTxt("<");
    button[3].setTxt(">");
    button[4].setTxt(L"Wyjście");

    // Pozycjonowanie przycisków
    placeButtons();
}















