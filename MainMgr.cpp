#include "MainMgr.hpp"

#include <cstdio>

MainMgr::MainMgr(sf::RenderWindow *window):
    window      (window)
{
    setupButtons();             /*  0) Start / Stop
                                 *  1) Wyjście
                                 *  2) Opcje
                                 *  3) <
                                 *  4) >
                                 */
}

int MainMgr::main()
{
    int ret = 0;

    while(window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            ret = 6;
        else if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Escape)
                ret = 6;
        }

        // Przyciski ---------------------------------------

        if(button[0].button(event)) // Start / Stop
        {
            if(button[0].getTxt().getString() == "Start")
            {
                button[0].setTxt("Stop");
                ret = 1;
            }
            else
            {
                button[0].setTxt("Start");
                ret = 2;
            }
        }

        if(button[1].button(event)) // Wyjscie
            ret = 6;

        if(button[2].button(event)) // Opcje
            ret = 3;

        if(button[3].button(event)) // <
            ret = 4;

        if(button[4].button(event)) // >
            ret = 5;
    }

    for(int i = 0; i < 5; ++i)
        button[i].draw();

    window->display();
    window->clear(sf::Color(128, 128, 128));

    if(ret) printf("MainMgr: %i\n", ret);

    return ret;
}

void MainMgr::placeButtons()
{
    button[0].setPos(window->getSize().x * 0.99 - button[0].getSiz().x, window->getSize().y * 0.02);
    button[1].setPos(window->getSize().x * 0.99 - button[1].getSiz().x, window->getSize().y * 0.98 - height);
    button[2].setPos(window->getSize().x * 0.99 - button[2].getSiz().x, window->getSize().y * 0.04 + height);
    button[3].setPos(window->getSize().x * 0.99 - button[2].getSiz().x, window->getSize().y * 0.06 + height * 2);
    button[4].setPos(window->getSize().x * 0.99 - button[4].getSiz().x, button[3].getPos().y);
    //button[].setPos();
}

void MainMgr::setupButtons()
{
    for(int i = 0; i < amount; ++i)
    {
        button[i].setDefCol(255, 64, 64);
        button[i].setHovCol(64, 255, 64);
        button[i].setActCol(64, 64, 255);
        button[i].setWin(*window);
        button[i].setTex("Images/button.png");
        button[i].setSiz(width, height);
        button[i].setTxtScl(0.4);
        button[i].setTxtMrg(45);

        sf::Text text;
        text.setFillColor(sf::Color(0, 0, 0));
        text.setOutlineColor(sf::Color(255, 255, 255));
        text.setOutlineThickness(1);

        button[i].setTxt(text);
    }

    // Dodatkowe ustawienia 3) "<" i 4) ">"
    button[3].setSiz(height * 0.75, height * 0.75); // <
    button[4].setSiz(height * 0.75, height * 0.75); // >

    button[3].setTxtMrg(20);
    button[4].setTxtMrg(20);

    // Tekst przycisków
    button[0].setTxt("Start");
    button[1].setTxt("Wyjscie");
    button[2].setTxt("Opcje");
    button[3].setTxt("<");
    button[4].setTxt(">");
    //button[].setTxt("");

    // Pozycje przycisków
    placeButtons();
}















