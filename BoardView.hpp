#ifndef BoardView_hpp
#define BoardView_hpp

#include <SFML/Graphics.hpp>

#include "Direction.hpp"

class BoardView
{
public:
    BoardView();                                        // Konstruktor

    void draw();                                        // Rysuje mape na scenie

    void setCol(sf::Vector2u pos, sf::Color color);     // Zmienia kolor w danym polu,
                                                        // jeżli wykroczy poza zakres nie zrobi nic :p

    void update();                                      // Ustawia wielkość i ustawia mape w odpowiednim miejscu :p

    void addArea(uint16_t extend, Direction dir);       // Zmienia rozmiar textury

    bool setView(sf::IntRect pos);                      // Zmienia pozycje mapy w sprajcie

    void setDefCol(sf::Color col);                      // Zmienia domyślny kolor nowych pól

    void setWin(sf::RenderWindow *win);                 // Ustawia okno

    // Pobieranie ustawień
    // -------------------------------------------------

    sf::Vector2u    getMapSiz()     {return tex.getSize();}

    sf::IntRect     getView()       {return area;}

    sf::Color       getDefCol()     {return defCol;}

private:
    sf::RenderWindow *window;                           // Okno :D

    sf::Sprite spr;                                     // Sprajt mapy ;)
    sf::Texture tex;                                    // Textura mapy
    sf::Image cell;                                     // Jedno pole

    sf::Vector2f sprSiz;                                // Rozmiar sprajta

    sf::IntRect area;                                   // Wyświetlany obszar

    sf::Color defCol;                                   // Domyślny kolor nowych pól

    sf::Sprite bgSprite;                                // Podkładka pod sprajta która tak naprawde jest ramką
    sf::Texture bgTexture;                              // Textura do background XD
};

#endif // BoardView_hpp



















