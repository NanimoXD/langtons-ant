#ifndef Button_hpp
#define Button_hpp

class Button
{
    sf::Texture texture;
    sf::Sprite sprite;

    sf::Font font;
    sf::Text text;

    sf::Vector2f pisition;
    sf::Vector2f size;

    sf::RenderWindow *window;

public:
    // Konstruktor
    Button(sf::RenderWindow &win, sf::Vector2f pos, sf::Vector2f siz, std::string str);

    // Ju� te� zrobie po kilka bo nie moge by� gorszy XD

    // Ustawia texture, skaluje j� do rozmiar�w przycisku
    setTexture(sf::Texture tex);
    setTexture(sf::Image tex);

    // Ustawia nowy tekst
    setTxt(sf::Text txt);
    setTxt(sf::String txt);
    setTxt(std::string txt);

    // Ustawia now� wielko��

    setSiz(sf::Vector2f siz);
    setSiz(float x, float y);

    // Ustawia now� pozycje
    setPos(sf::Vector2f pos);
    setPos(float x, float y);

    // Ustawia zwyk�y koloru
    setDefCol(sf::Color col);
    setDefCol(char r, char g, char b, char a); // a domy�lnie 255

    // Ustawia kolor po najechaniu
    setHovCol(sf::Color col);
    setHovCol(char r, char g, char b, char a); // a domy�lnie 255

    // Ustawia kolor podczas klikni�cia
    setActCol(sf::Color col);
    setActCol(char r, char g, char b, char a); // a domy�lnie 255
};


#endif // Button_hpp
