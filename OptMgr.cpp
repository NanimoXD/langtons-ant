#include "OptMgr.hpp"

OptMgr::OptMgr(MainWin &_mainWin):
    mainWin      (_mainWin)
{
    setupButtons();                                 /*  0) Pełny ekran
                                                     *  1) Przycisk 2
                                                     *  2) Przycisk 3
                                                     *  3) Przycisk 4
                                                     *  4) Przycisk 5
                                                     *  5) Przycisk 6
                                                     *  6) Przycisk 7
                                                     *  7) Przycisk 8
                                                     *  8) Przycisk 9
                                                     *  9) Przycisk 10
                                                     *  10) Przycisk 11
                                                     *  11) Przycisk 12
                                                     *  12) Przycisk 13
                                                     *  13) Przycisk 14
                                                     *  14) Przycisk 15
                                                     *  15) Przycisk 16
                                                     *  16) Przycisk 17
                                                     *  17) Przycisk 18
                                                     *  18) Powrót
                                                     */
}

MgrRet OptMgr::main()
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
                if(!mainWin.window->waitEvent(event));
            }while(event.type != sf::Event::GainedFocus);

        }
        else if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Escape)
                ret.close = true;
        }
    }

    // Przyciski ---------------------------------------

    for(int i = 0; i < amount; ++i)     // Przyciski od 1 do 19
    {
        if(i >= 1 && i <= 5)
            continue;

        if(button[i].button())
            ret.id = (i + 1) * 10;
    }

    return ret;
}

void OptMgr::placeButtons()
{
    // Pierwsza kolumna
    button[0].setPos(mainWin.window->getSize().x * 0.2 - width / 2, mainWin.window->getSize().y * 0.02);    // Pełny ekran
    button[1].setPos(mainWin.window->getSize().x * 0.2 - width / 2, mainWin.window->getSize().y * 0.16);
    button[2].setPos(mainWin.window->getSize().x * 0.2 - width / 2, mainWin.window->getSize().y * 0.30);
    button[3].setPos(mainWin.window->getSize().x * 0.2 - width / 2, mainWin.window->getSize().y * 0.44);
    button[4].setPos(mainWin.window->getSize().x * 0.2 - width / 2, mainWin.window->getSize().y * 0.58);
    button[5].setPos(mainWin.window->getSize().x * 0.2 - width / 2, mainWin.window->getSize().y * 0.72);

    // Druga kolumna
    button[6].setPos(mainWin.window->getSize().x * 0.5 - width / 2, mainWin.window->getSize().y * 0.02);
    button[7].setPos(mainWin.window->getSize().x * 0.5 - width / 2, mainWin.window->getSize().y * 0.16);
    button[8].setPos(mainWin.window->getSize().x * 0.5 - width / 2, mainWin.window->getSize().y * 0.30);
    button[9].setPos(mainWin.window->getSize().x * 0.5 - width / 2, mainWin.window->getSize().y * 0.44);
    button[10].setPos(mainWin.window->getSize().x * 0.5 - width / 2, mainWin.window->getSize().y * 0.58);
    button[11].setPos(mainWin.window->getSize().x * 0.5 - width / 2, mainWin.window->getSize().y * 0.72);

    //Trzecia kolumna
    button[12].setPos(mainWin.window->getSize().x * 0.8 - width / 2, mainWin.window->getSize().y * 0.02);
    button[13].setPos(mainWin.window->getSize().x * 0.8 - width / 2, mainWin.window->getSize().y * 0.16);
    button[14].setPos(mainWin.window->getSize().x * 0.8 - width / 2, mainWin.window->getSize().y * 0.30);
    button[15].setPos(mainWin.window->getSize().x * 0.8 - width / 2, mainWin.window->getSize().y * 0.44);
    button[16].setPos(mainWin.window->getSize().x * 0.8 - width / 2, mainWin.window->getSize().y * 0.58);
    button[17].setPos(mainWin.window->getSize().x * 0.8 - width / 2, mainWin.window->getSize().y * 0.72);
    button[18].setPos(mainWin.window->getSize().x * 0.8 - width / 2, mainWin.window->getSize().y * 0.86); // Powrót
}

void OptMgr::setupButtons()
{
    button[0].setDefCol(255, 64, 64);
    button[0].setHovCol(64, 255, 64);
    button[0].setActCol(64, 64, 255);
    button[0].setWin(*mainWin.window);
    button[0].setTex("Images/button.png");
    button[0].setSiz(width, height);
    button[0].setTxtScl(0.4);

    sf::Text text;
    text.setFillColor(sf::Color(0, 0, 0));
    text.setOutlineColor(sf::Color(255, 255, 255));
    text.setOutlineThickness(1);

    button[0].setTxt(text);

    for(int i = 1; i < amount; ++i)
        button[i] = button[0];

    // Tekst przycisków
    button[0].addStr(L"Pełny ekran");
    button[1].addStr("Przycisk 2");
    button[2].addStr("Przycisk 3");
    button[3].addStr("Przycisk 4");
    button[4].addStr("Przycisk 5");
    button[5].addStr("Przycisk 6");

    button[6].addStr("Brak");
    button[6].addStr(L"Biały");
    button[6].addStr("Czerwony");
    button[6].addStr(L"Żółty");
    button[6].addStr("Zielony");
    button[6].addStr("Niebieski");
    button[6].addStr("Fioletowy");

    for(int i = 7; i < 12; ++i)
        button[i] = button[6];

    button[12].addStr("Prawo");
    button[12].addStr("Lewo");
    button[12].addStr("Prosto");
    button[12].addStr("W tył");

    for(int i = 13; i < 18; ++i)
        button[i] = button[12];

    button[18].addStr(L"Powrót");

    // Pozycjonowanie przycisków
    placeButtons();
}





















