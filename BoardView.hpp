#ifndef BoardView_hpp
#define BoardView_hpp

#include <SFML/Graphics.hpp>

#include "Direction2.hpp"

class BoardView
{
public:
    BoardView();                                        // Konstruktor

    void newBoard();                                    // Tworzy nową mape (wywoływne przez konstruktor)

    void draw();                                        // Rysuje mape na scenie

    bool setCol(sf::Vector2u pos, sf::Color color);     // Zmienia kolor w danym polu,
                                                        // jeżli wykroczy poza zakres nie zrobi nic :p

    void update();                                      // Ustawia wielkość i ustawia mape w odpowiednim miejscu :p

    void addArea(uint16_t extend, Direction2 dir);       // Zmienia rozmiar textury

    void setCenter(sf::Vector2i pos);                   // Zmienia pozycje środka widoku

    void setViewSiz(sf::Vector2u siz);                  // Zmienia pozycje mapy w sprajcie

    void setViewScl(float scl);                         // Ustawia skale przybliżenia

    void setDefCol(sf::Color col);                      // Zmienia domyślny kolor nowych pól

    void setWin(sf::RenderWindow *win);                 // Ustawia okno

    // Pobieranie ustawień
    // -------------------------------------------------

    sf::Vector2u    getSiz()        {return tex.getSize();}

    sf::Vector2i    getCenter()     {return center;}

    sf::Vector2u    getViewSiz()    {return sf::Vector2u(area.width, area.height);}

    float           getViewScl()    {return viewScl;}

    sf::Color       getDefCol()     {return defCol;}

private:
    sf::RenderWindow *window;                           // Okno :D

    sf::Sprite spr;                                     // Sprajt mapy ;)
    sf::Texture tex;                                    // Textura mapy
    sf::Image cell;                                     // Jedno pole

    sf::Vector2i center;                                // Środek wyświetlanego obrazu
    sf::IntRect area;                                   // Wyświetlany obszar
    float viewScl;                                      // Skala przybliżenia

    sf::Color defCol;                                   // Domyślny kolor nowych pól

    sf::Sprite bgSprite;                                // Podkładka pod sprajta która tak naprawde jest ramką
    sf::Texture bgTexture;                              // Textura do background XD
};

#endif // BoardView_hpp



















