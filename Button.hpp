#ifndef Button_hpp
#define Button_hpp

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Button
{
    sf::Texture texture;
    sf::Sprite sprite;

    sf::Color defCol;
    sf::Color hovCol;
    sf::Color actCol;

    sf::Font font;
    sf::Text text;
    float textScale;

    sf::Vector2f position;
    sf::Vector2f size;

    bool hover;
    bool pressed;
    bool broken;

    sf::RenderWindow *window;

    void constructor(); // :p

    void updateSprite();

public:
    // Konstruktor
    Button(sf::RenderWindow &win, sf::Vector2f pos, sf::Vector2f siz, std::string str = "");
    Button(sf::RenderWindow &win, float posx, float posy, float sizx, float sizy, std::string str = "");

    // Tu sie dzieje wszystko :D
    // Zwraca prawde jeśli przycisk został aktywowany :D :p
    bool button(sf::Event &event);

    // Już też zrobie po kilka bo nie moge być gorszy XD

    // Ustawia texture i skaluje ją do rozmiarów przycisku
    // Niestety da sie ustawić tylko raz do czasu wywołania button()
    // Później ustawia sie białe tło i dupa :p
    void setTex(sf::Texture tex);
    void setTex(sf::Image tex);
    bool setTex(sf::String tex); // Źródło textury

    // Ustawia nową wielkość
    void setSiz(sf::Vector2f siz);
    void setSiz(float x, float y);

    // Ustawia nową pozycje lewego górnego rogu
    void setPos(sf::Vector2f pos);
    void setPos(float x, float y);

    // Ustawia czcionke
    void setFon(sf::Font &fon);
    bool setFon(sf::String fon); // Źródło czcionki

    // Ustawia nowy tekst
    void setTxt(sf::Text txt); // Kolory, text i styl
    void setTxt(sf::String txt); // Trzeba uważać żeby nie był dłuższy od przycisku :p

    // Ustawia skale czcionki do wysokości przycisku
    void setTxtScl(float y);

    // Ustawia zwykły koloru
    void setDefCol(sf::Color col);
    void setDefCol(char r, char g, char b, char a = 255);

    // Ustawia kolor po najechaniu
    void setHovCol(sf::Color col);
    void setHovCol(char r, char g, char b, char a = 255);

    // Ustawia kolor podczas kliknięcia
    void setActCol(sf::Color col);
    void setActCol(char r, char g, char b, char a = 255);

    // Ustawia nowe okno
    void setWin(sf::RenderWindow &win);
};

#endif // Button_hpp














