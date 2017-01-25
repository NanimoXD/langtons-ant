#include "MainMgr.hpp"

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

MgrRet MainMgr::main()
{
    MgrRet ret;

    while(mainWin.window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            ret.close = true;
        else if(event.type == sf::Event::Resized)
        {
            mainWin.newWin(sf::Vector2u(event.size.width, event.size.height));
            ret.resize = true;
        }
        else if(event.type == sf::Event::LostFocus)
        {
            do
            {
                if(!mainWin.window->pollEvent(event))
                    sf::sleep(sf::milliseconds(100));
            }while(event.type != sf::Event::GainedFocus);

        }
        else if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Escape)
                ret.close = true;
        }
    }

    // Przyciski ---------------------------------------

    switch(button[0].button())  // Start / Stop
    {
    case 1:
        ret.id = 10;
        break;
    case 2:
        ret.id = 11;
        break;
    }

    if(button[1].button()) ret.id = 20;         // Opcje
    if(button[2].button()) ret.id = 30;         // <
    if(button[3].button()) ret.id = 40;         // >
    if(button[4].button()) ret.close = true;    // Wyjście

    mainWin.window->display();
    mainWin.window->clear(sf::Color(128, 128, 128));

    if(ret.id) printf("MainMgr: %2i\t", ret.id);

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
    button[0].addStr("Start");
    button[0].addStr("Stop");
    button[1].addStr("Opcje");
    button[2].addStr("<");
    button[3].addStr(">");
    button[4].addStr(L"Wyjście");

    // Pozycjonowanie przycisków
    placeButtons();
}















