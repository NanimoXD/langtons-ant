#ifndef Button_hpp
#define Button_hpp

#include <SFML/Graphics.hpp>

class Button
{
    sf::Texture texture;
    sf::Sprite sprite;

    sf::Color defCol;
    sf::Color hovCol;
    sf::Color actCol;

    sf::Font font;
    sf::Text text;
    short marginLeft;
    float textScale;

    sf::Vector2f position;
    sf::Vector2f size;

    bool hover;
    bool pressed;

    sf::RenderWindow *window;

    void constructor(); // :p

    void updateSprite();

public:
    // Konstruktory
    Button();
    Button(sf::RenderWindow &win, sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f siz = sf::Vector2f(0, 0), std::string str = "");
    Button(sf::RenderWindow &win, float posx = 0, float posy = 0, float sizx = 0, float sizy = 0, std::string str = "");

    // Zwraca prawde jeśli przycisk został aktywowany :D :p
    bool button(sf::Event &event);

    // Rysuje przycisk na scenie :D (Jeśli window != nullptr)
    void draw();

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

    sf::Texture     getTex()        {return texture;};

    sf::Vector2f    getSiz()        {return size;};

    sf::Vector2f    getPos()        {return position;};

    sf::Font        getFon()        {return font;};

    sf::Text        getTxt()        {return text;};

    short           getMrg()        {return marginLeft;};

    float           getTxtScl()     {return textScale;};

    sf::Color       getDefCol()     {return defCol;};

    sf::Color       getHovCol()     {return hovCol;};

    sf::Color       getActCol()     {return actCol;};
};

#endif // Button_hpp

















