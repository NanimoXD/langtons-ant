#ifndef Button_hpp
#define Button_hpp

#include <SFML/Graphics.hpp>

#include <queue>

class Button
{
public:
    // Konstruktory
    Button();
    Button(sf::RenderWindow &win, sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f siz = sf::Vector2f(0, 0), std::string str = "");
    Button(sf::RenderWindow &win, float posx = 0, float posy = 0, float sizx = 0, float sizy = 0, std::string str = "");

    // Rysuje przycisk, zwraca numer opcji przycisku jeśli został przyciśnięty :D :p
    short button();

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

    // Kopiuje kolory i styl
    void setTxt(sf::Text txt);

    // Dodaje nowy text na koniec kolejki
    void addStr(sf::String txt); // Trzeba uważać żeby nie był dłuższy od przycisku :p

    // Czyści kolejke
    void clrStr();

    // Zmienia tekst na kolejny w kolejce i zwraca jego numer
    short nxtStr();

    // Ustawia margines od lewej w pixelach
    void setTxtMrg(short mrg);

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


    // Wszystko to samo co wyżej tylko w drugą strone :p
    // -------------------------------------------------
    // Nie chce mi sie tego pisać w cpp :p

    bool            isPrst()        {return pressed;}

    bool            isHovr()        {return hover;}

    sf::Texture     getTex()        {return texture;}

    sf::FloatRect   getRec()        {return area;}

    sf::Font        getFon()        {return font;}

    sf::Text        getTxt()        {return text;}

    short           getTxtNum()     {return textID;}

    short           getMrg()        {return marginLeft;}

    float           getTxtScl()     {return textScale;}

    sf::Color       getDefCol()     {return defCol;}

    sf::Color       getHovCol()     {return hovCol;}

    sf::Color       getActCol()     {return actCol;}

private:
    sf::Texture texture;
    sf::Sprite sprite;

    sf::Color defCol;
    sf::Color hovCol;
    sf::Color actCol;

    sf::Font font;
    sf::Text text;
    unsigned short textID;
    std::queue<std::string> strings;
    short marginLeft;
    float textScale;

    sf::FloatRect area;

    bool hover;
    bool broken;
    bool pressed;

    sf::RenderWindow *window;

    void constructor(); // :p

    void updateSprite();
};

#endif // Button_hpp

















