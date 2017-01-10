#ifndef BOARD_H
#define BOARD_H

#include <SFML/System/Vector2.hpp>
#include <array>


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
     * W niektórych sytuacjach może to spowodować utratę informacji
     */
    void resize(const sf::Vector2u &new_size, const sf::Vector2i &current_map_point = sf::Vector2i());

    /* Czyści planszę, tj. po wywołaniu ma ona rozmiar (0, 0) */
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

private:
    FieldColorId **data;
    sf::Vector2u data_size;
    FieldColorId new_field_color;
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

#endif // BOARD_H
