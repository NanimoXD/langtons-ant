#ifndef BOARD_H
#define BOARD_H

#include "Ant.hpp"
#include <SFML/System/Vector2.hpp>


/* Nic innego jak indeks koloru w regule symulacji */
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
    Board(const sf::Vector2u &size, FieldColorId color_id = 0);

    /* Konstruuje kopię planszy */
    Board(const Board &b);

    ~Board();

    /* Zmienia rozmiar planszy, odpowiednio ją pomniejszając lub powiększając.
     * Dodatkowy argument określa opcjonalny wektor przesunięcia obecnej planszy oraz mrówki.
     * Jeżeli zmiana powoduje powiększenie planszy, nowe pola zostaną zainicjalizowane ID koloru z getNewCellColor().
     * Dane (lub mrówka) wykraczające poza planszę zostaną pominięte.
     */
    void resize(const sf::Vector2u &new_size, const sf::Vector2i &current_map_point = sf::Vector2i());

    /* Czyści planszę, tj. po wywołaniu ma ona rozmiar (0, 0). Ewentualna obecna mrówka zostaje usunięta */
    void clear();

    /* Metody do pobierania rozmiaru planszy */
    inline sf::Vector2u size() const;
    inline unsigned int width() const;
    inline unsigned int height() const;

    /* Zmienia / pobiera id koloru pojedynczego pola. Nie sprawdza czy istnieje, dlatego pilnować się :D */
    void setFieldColor(const sf::Vector2u &point, FieldColorId color_id);
    FieldColorId getFieldColor(const sf::Vector2u &point) const;

    /* Id koloru nowych pól w momecie ich tworzenia. Domyślnie jest to 0 */
    void setNewFieldColor(FieldColorId color_id);
    inline FieldColorId getNewFieldColor() const;

    /* Umiejscawia mrówkę na planszy.
     * Jeśli na planszy jest już mrówka, zostaje zastąpiona nową.
     * Mrówka musi posiadać pozycję odpowiednią do rozmiaru planszy, aby została przypisana i zastąpiła poprzednią.
     */
    void placeAnt(const Ant &a);

    /* Zwraca true, jeżeli mrówka istnieje na plaszy (i ma poprawne pozycje), w innym wypadku false */
    bool hasAnt() const;

    /* Usuwa mrówkę z planszy */
    void removeAnt();

    /* Zwraca obiekt mrówki. Dane są uznawane za poprawne, gdy hasAnt() zwraca true, w innym przypadku pozycja jest niepoprawna */
    inline const Ant & getAnt() const;

    /* Ustawia pojedyncze dane mrówki. Tworzy ją, gdy nie istnieje, używając konstuktora domyślnego.
     * Pozycja musi być odpowiednia do rozmiaru planszy.
     */
    void setAntPosition(const sf::Vector2u &position);
    void setAntDirection(Direction dir);

    Board & operator=(const Board &b);

    /* Wymienia dane plansz. Obiekt wywołujący otrzymuje dane parametru, a temu z kolei przypisuje się dane obiektu */
    void swap(Board &b);

private:
    void copyData(const Board &b);

    FieldColorId **data;
    sf::Vector2u data_size;
    FieldColorId new_field_color;
    Ant ant;
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

const Ant & Board::getAnt() const
{ return ant; }


#endif // BOARD_H
