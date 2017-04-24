#include "MainMgr.hpp"

MainMgr::MainMgr(sf::RenderWindow *_window):
    window      (_window)
{
    setupButtons();             /*  0) Start / Stop
                                 *  1) Restart
                                 *  2) Opcje
                                 *  3) <
                                 *  4) >
                                 *  5) Wyjście
                                 */
}

int MainMgr::main()
{
    int ret = 0;

    switch(button[0].button())  // Start / Stop
    {
    case 1:
        ret = 10;
        break;
    case 2:
        ret = 11;
        break;
    }

    for(int i = 1; i < amount; ++i)
        if(button[i].button())
            ret = (i + 1) * 10;

    return ret;
}

void MainMgr::placeButtons()
{
    button[0].setPos(window->getSize().x * 0.99 - width, window->getSize().y * 0.02);               // Start / Stop
    button[1].setPos(window->getSize().x * 0.99 - width, window->getSize().y * (0.17));             // Restart
    button[2].setPos(window->getSize().x * 0.99 - width, window->getSize().y * (0.32));             // Opcje
    button[3].setPos(window->getSize().x * 0.99 - width, window->getSize().y * (0.47));             // <
    button[4].setPos(window->getSize().x * 0.99 - height * 0.75, window->getSize().y * (0.47));     // >
    button[5].setPos(window->getSize().x * 0.99 - width, window->getSize().y * 0.98 - height);      // Wyjście
}

void MainMgr::setupButtons()
{
    button[0].setDefCol(255, 64, 64);
    button[0].setHovCol(64, 255, 64);
    button[0].setActCol(64, 64, 255);
    button[0].setWin(*window);
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

    // Tekst przycisków
    button[0].addStr("Start");
    button[0].addStr("Stop");
    button[1].addStr("Restart");
    button[2].addStr("Opcje");
    button[3].addStr("+");
    button[4].addStr("-");
    button[5].addStr(L"Wyjście");

    // Dodatkowe ustawienia 3) "+" i 4) "-"
    button[3].setSiz(height * 0.75, height * 0.75);
    button[4].setSiz(height * 0.75, height * 0.75);

    button[3].setTxtMrg(20);
    button[4].setTxtMrg(20);

    // Pozycjonowanie przycisków
    placeButtons();
}















