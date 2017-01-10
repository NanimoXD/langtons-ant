#include "Board.hpp"


Board::Board()
    : Board(sf::Vector2u(), 0)
{ }

Board::Board(const sf::Vector2u &size, FieldColorId color_id)
    : data(nullptr),
      new_field_color(color_id)
{
    resize(size);
}

Board::~Board()
{
    clear();
}

void Board::resize(const sf::Vector2u &new_size, const sf::Vector2i &current_map_point)
{
    /* Unikam niepotrzebnych wywołań */
    if (size() == new_size && current_map_point == sf::Vector2i())
        return;

    /* Unikam inicjalizacji tablic o długościach 0 */
    if (new_size.x == 0 || new_size.y == 0) {
        clear();
        return;
    }

    sf::Vector2i d_size_signed = sf::Vector2i(data_size.x, data_size.y);

    /* Tablica wskaźników na rzędy */
    FieldColorId **new_data = new FieldColorId *[new_size.y];

    /* Iteracja po rzędach, alokacja */
    for (unsigned int row = 0; row < new_size.y; ++row) {
        FieldColorId *row_data = new FieldColorId[new_size.x];

        for (unsigned int column = 0; column < new_size.x; ++column) {
            sf::Vector2i source_point = sf::Vector2i(column, row) - current_map_point;

            if (data && source_point.x > -1 && source_point.y > -1 &&
                source_point.x < d_size_signed.x && source_point.y < d_size_signed.y) {

                row_data[column] = getFieldColor(sf::Vector2u(source_point.x, source_point.y));
            } else {
                row_data[column] = getNewFieldColor();
            }
        }

        new_data[row] = row_data;
    }

    /* Dealokacja dawnych danych i przypisanie nowych */
    clear();

    data = new_data;
    data_size = new_size;
}

void Board::clear()
{
    if (data) {
        for (unsigned int row = 0; row < data_size.y; ++row)
            delete [] data[row];

        delete [] data;

        data = nullptr;
        data_size = sf::Vector2u();
    }
}