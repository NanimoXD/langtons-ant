#include "OptMgr.hpp"

OptMgr::OptMgr(MainWin &_mainWin):
    mainWin      (_mainWin)
{
    setupButtons();                                 /*  0) Pełny ekran
                                                     *  1)
                                                     *  2) Reset
                                                     *  3)
                                                     *  4)
                                                     *  5)
                                                     *  6) Kolor 7
                                                     *  7) Kolor 8
                                                     *  8) Kolor 9
                                                     *  9) Kolor 10
                                                     *  10) Kolor 11
                                                     *  11) Kolor 12
                                                     *  12) Kolor 13
                                                     *  13) Kolor 14
                                                     *  14) Kolor 15
                                                     *  15) Kolor 16
                                                     *  16) Kolor 17
                                                     *  17) Kolor 18
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
                ret.id = 190;
        }
    }

    // Przyciski ---------------------------------------

    for(int i = 0; i < amount; ++i)     // Przyciski od 1 do 19
    {
        if(i == 1 || i == 3 || i == 4 || i == 5)
            continue;

        if(button[i].button())
            ret.id = (i + 1) * 10;
    }

    return ret;
}

void OptMgr::placeButtons()
{
    // Pierwsza kolumna
    button[0].setPos(mainWin.window->getSize().x * 0.2 - width / 2, mainWin.window->getSize().y * 0.02);
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
    button[18].setPos(mainWin.window->getSize().x * 0.8 - width / 2, mainWin.window->getSize().y * 0.86);
}

void OptMgr::setStrId(uint8_t num, short id)
{
    if(num >= amount || id > button[num].getTxtNum() || id < 1) return;

    while(button[num].getTxtId() != id) button[num].nxtStr();
}

void OptMgr::setupButtons()
{
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
    button[2].addStr("Reset");

    button[6].addStr("Brak");
    button[6].addStr("Prawo");
    button[6].addStr("Lewo");
    button[6].addStr("Prosto");
    button[6].addStr(L"W tył");

    for(int i = 7; i < 18; ++i)
        button[i] = button[6];

    // Druga kolumna

    button[6].setDefCol(192, 32, 32); // Czerwony
    button[6].setHovCol(224, 32, 32);
    button[6].setActCol(255, 32, 32);

    button[7].setDefCol(192, 192, 32); // Żółty
    button[7].setHovCol(224, 224, 32);
    button[7].setActCol(255, 255, 32);

    button[8].setDefCol(32, 192, 32); // Zielony
    button[8].setHovCol(32, 224, 32);
    button[8].setActCol(32, 255, 32);

    button[9].setDefCol(32, 192, 192); // Aqua
    button[9].setHovCol(32, 224, 224);
    button[9].setActCol(32, 255, 255);

    button[10].setDefCol(32, 32, 192); // Niebieski
    button[10].setHovCol(32, 32, 224);
    button[10].setActCol(32, 32, 255);

    button[11].setDefCol(192, 32, 192); // Różowy
    button[11].setHovCol(224, 32, 224);
    button[11].setActCol(255, 32, 255);

    // Trzecia kolumna

    button[12].setDefCol(192, 96, 32); // Pomarańczowy
    button[12].setHovCol(224, 128, 32);
    button[12].setActCol(255, 140, 32);

    button[13].setDefCol(96, 192, 32); // Taki jakiś pomiędzy żółtym a zielonym
    button[13].setHovCol(128, 224, 32);
    button[13].setActCol(140, 255, 32);

    button[14].setDefCol(32, 192, 96); // Taki morski XD
    button[14].setHovCol(32, 224, 128);
    button[14].setActCol(32, 255, 140);

    button[15].setDefCol(32, 96, 192); // Jasny niebieski
    button[15].setHovCol(32, 128, 224);
    button[15].setActCol(32, 140, 255);

    button[16].setDefCol(96, 32, 192); // Fioletowy
    button[16].setHovCol(128, 32, 224);
    button[16].setActCol(140, 32, 255);

    button[17].setDefCol(192, 32, 96); // Taki nie mam pojęcia jaki a coś w stylu ze czerwony
    button[17].setHovCol(224, 32, 128);
    button[17].setActCol(255, 32, 140);

    button[18].addStr(L"Powrót");

    // Pozycjonowanie przycisków
    placeButtons();
}





















