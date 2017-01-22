#ifndef BoardView_hpp
#define BoardView_hpp

#include <SFML/Graphics.hpp>

class BoardView
{
public:
    BoardView();                                    // Konstruktor

    void draw();                                    // Rysuje mape na scenie

    void setCol(sf::Vector2u pos, sf::Color color); // Zmienia kolor w danym polu,
                                                    // jeżli wykroczy poza zakres nie zrobi nic :p

    void setSprPos(sf::Vector2f pos);               // Zmienia pozycje sprita w oknie

    void setSprSiz(sf::Vector2u siz);               // Zmienia rozmiar textury w pixelach

    void setMapPos(sf::Vector2u pos);               // Zmienia pozycje mapy w sprajcie

    void setMapSiz(sf::Vector2u siz);               // Zmienia ilość wyświetlanych pól

    void setWin(sf::RenderWindow *win);             // Ustawia okno

private:
    sf::RenderWindow *window;                       // Okno :D

    sf::Sprite spr;                                 // Sprajt ;)
    sf::Texture *normalTex,                         // Zwykła textura
                *checkeredTex;                      // Textura w kratke

    bool checked;                                   // Jeśli prawda używana jest kratkowana textura
    const sf::Vector2u checkeredCellSiz;            // Rozmiary pola kratkowanej textury

    sf::Vector2u sprSiz,                            // Rozmiar sprajta
                 mapSiz;                            // Ilość komórek mapy

    sf::Rect<int> mapPos;                           // Wyświetlany obszar
};

#endif // BoardView_hpp



















