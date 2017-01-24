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

    /* Zachowuję mrówkę, gdyż clear() ją usuwa */
    bool had_ant = hasAnt();
    Ant ant_copy = ant;

    /* Dealokacja dawnych danych i przypisanie nowych */
    clear();
    data = new_data;
    data_size = new_size;

    /* Zmiana rozmiaru zachodzi później i mrówka nieprzypisana przez użytkownika może pojawić się na planszy,
     * konieczne kolejne usunięcie */
    removeAnt();

    /* Przesuwam mrówkę razem z planszą */
    if (had_ant) {
        int x = (int) ant_copy.getPosition().x + current_map_point.x;
        int y = (int) ant_copy.getPosition().y + current_map_point.y;

        if (x > -1 && y > -1) {
            ant_copy.setPosition(sf::Vector2u((unsigned int) x, (unsigned int) y));
            placeAnt(ant_copy);
        }
    }
}

void Board::clear()
{
    if (data) {
        for (unsigned int row = 0; row < data_size.y; ++row)
            delete [] data[row];

        delete [] data;

        data = nullptr;
        data_size = sf::Vector2u();

        /* Nie ma opcji żeby jakaś mróweczka przetrwała apokalipsę */
        removeAnt();
    }
}

void Board::placeAnt(const Ant &a)
{
    /* Na pustej planszy ani na pozycjach przekraczających rozmiar nie można umieszczać mrówki */
    if (a.getPosition().x < width() && a.getPosition().y < height())
        ant = a;
}

bool Board::hasAnt() const
{
    return ant.getPosition().x < width() && ant.getPosition().y < height();
}

void Board::removeAnt()
{
    ant = Ant(size()); // tzn. przekracza rozmiar planszy, taki punkt nie istnieje
}

void Board::setAntPosition(const sf::Vector2u &position)
{
    Ant ant_new = hasAnt() ? ant : Ant();
    ant_new.setPosition(position);
    placeAnt(ant_new);
}

void Board::setAntDirection(Direction dir)
{
    Ant ant_new = hasAnt() ? ant : Ant();
    ant_new.setDirection(dir);
    placeAnt(ant_new);
}
