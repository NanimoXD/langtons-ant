#ifndef BOARD_H
#define BOARD_H

#include "Ant.hpp"
#include <SFML/System/Vector2.hpp>


/* Nic innego jak indeks koloru w palecie */
typedef unsigned int FieldColorId;


/* Klasa reprezentująca planszę.
 * X, Y są nieujemnymi współrzędnymi.
 * Punkt (0, 0) reprezentuje górny lewy róg planszy
 */

class Board
{
public:
    /* Konstruuje pustą planszę */
    Board();

    /* Konstruuje planszę o wskazanym rozmiarze, z polami zainicjowanymi na przekazany kolor. Przypisuje ten kolor jako domyślny */
    Board(const sf::Vector2u &size, FieldColorId color_id);

    ~Board();

    /* Zmienia rozmiar planszy, odpowiednio ją pomniejszając lub powiększając.
     * Jeżeli zmiana powoduje zwiększenie planszy, nowe pola zostaną zainicjalizowane kolorem (id) o wartości getNewCellColor().
     * Dodatkowy argument określa punkt, w jakim aktualne dane planszy zostaną umiejscowione po zmianie jej rozmiaru (w nowej planszy).
     * W niektórych sytuacjach może to spowodować utratę informacji lub mrówki.
     */
    void resize(const sf::Vector2u &new_size, const sf::Vector2i &current_map_point = sf::Vector2i());

    /* Czyści planszę, tj. po wywołaniu ma ona rozmiar (0, 0). Ewentualna obecna mrówka ginie, zostaje usunięta */
    void clear();

    /* Metody do pobierania rozmiaru planszy */
    inline sf::Vector2u size() const;
    inline unsigned int width() const;
    inline unsigned int height() const;

    /* Zmienia / pobiera id koloru pojedynczego pola. Nie sprawdza czy istnieje, dlatego pilnować się :D */
    void setFieldColor(const sf::Vector2u &point, FieldColorId color_id);
    FieldColorId getFieldColor(const sf::Vector2u &point) const;

    /* Kolor nowych pól przydzielanych w momecie ich tworzenia. Domyślnie jest to 0 */
    void setNewFieldColor(FieldColorId color_id);
    inline FieldColorId getNewFieldColor() const;

    /* Umiejscawia mrówkę na planszy, jeżeli argument jest prawidłowym wskaźnikiem.
     * Mrówka musi posiadać pozycję odpowiednią do rozmiaru planszy, inaczej nie zostanie przypisana, lecz zniszczona (brrr!).
     * Uwaga: klasa bierze odpowiedzialność za obiekt mrówki i usuwa ją w swoim destruktorze (użyj new).
     * Jeśli na planszy jest już mrówka, zostaje zastąpiona nową */
    void placeAnt(Ant *ant_ptr);

    /* Usuwa mrówkę z planszy, wywołuje jej destruktor. Gdy plansza nie ma mrówki, nic się nie dzieje */
    void removeAnt();

    /* Wskaźnik na mrówkę. Może być pusty */
    /** @todo W ten sposób można "hakować" położenie i nabroić, trzeba będzie coś pomyśleć */
    inline Ant * getAnt();

private:
    /* Blokuję kopiowanie obiektów, na razie nie potrzebna funkcjonalność */
    Board(const Board &) = delete;
    Board & operator=(const Board &) = delete;

    FieldColorId **data;
    sf::Vector2u data_size;
    FieldColorId new_field_color;
    Ant *ant;
};

sf::Vector2u Board::size() const
{ return data_size; }

unsigned int Board::width() const
{ return data_size.x; }

unsigned int Board::height() const
{ return data_size.y; }

inline void Board::setFieldColor(const sf::Vector2u &point, FieldColorId color_id)
{ data[point.y][point.x] = color_id; }

inline FieldColorId Board::getFieldColor(const sf::Vector2u &point) const
{ return data[point.y][point.x]; }

inline void Board::setNewFieldColor(FieldColorId color_id)
{ new_field_color = color_id; }

FieldColorId Board::getNewFieldColor() const
{ return new_field_color; }

Ant * Board::getAnt()
{ return ant; }

#endif // BOARD_H
