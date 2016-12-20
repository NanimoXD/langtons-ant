#ifndef ANTRULE_H
#define ANTRULE_H

#include "Direction.hpp"

#include <SFML/Graphics/Color.hpp>

#include <string>
#include <vector>
#include <utility>

typedef unsigned int uint;

/* Paleta to nic innego jak lista kolorów */

class AntRulePalette
{
public:
    AntRulePalette();
    AntRulePalette(const std::vector<sf::Color> &colors_db);
    AntRulePalette(std::vector<sf::Color> &&colors_db);

    inline std::vector<sf::Color> & data();
    inline const std::vector<sf::Color> & data() const;

    inline uint size() const;

    /* Domyślna paleta programu */
    static const AntRulePalette & defaultPalette();

private:
    std::vector<sf::Color> colors;
};

std::vector<sf::Color> & AntRulePalette::data()
{ return colors; }

const std::vector<sf::Color> & AntRulePalette::data() const
{ return colors; }

uint AntRulePalette::size() const
{ return colors.size(); }


/* Klasa reprezentująca regułę symulacji */

class AntRule
{
public:
    /* Para danych: przypisanie kierunku do koloru */
    typedef std::pair<Direction, sf::Color> Pair;

    /*
     * Koncept tekstowej reguły na podstawie https://en.wikipedia.org/wiki/Langton's_ant#Extension_to_multiple_colors
     * W skrócie:
     * - każdy kierunek jest reprezentowany jako pojedyncza litera
     *  * obsługiwane: L- Left, R - Right
     */

    /*
     * Uwagi do implementacji:
     * - lista pojedynczych przypisań (Pair) tworzy jedną, większą regułę symulacji
     * - inna kolejność kierunków da inną regułę
     * - każdy kierunek ma przypisany kolor; kolory mogą się powtarzać, nie są sprawdzane
     * - przekazanie pustej palety w argumencie spowoduje użycie domyślnej palety symulacji (AntRulePalette::defaultPalette())
     * - metody i konstruktor przyjmują na wejściu również małe znaki, tzn. 'r', 'l', ale dane zwracane zawsze mają postać typu "RL"
     * - jeżeli metoda przyjmuje listę, oczekuje się, że wszystkie[1] kierunki są obsługiwane, a ciągi tekstowe poprawne (np. "RR1" jest błędne)
     *  [1] tzn. tyle kierunków musi być obsługiwanych ile wynosi rozmiar palety
     * - faktyczna ilość reguł jest najmniejszą liczbą z ilości kierunków i długości palety
     */


    /* Konstruuje pusty obiekt bez par, dla którego isValid() zwraca false */
    AntRule();

    /* Konstruuje regułę na podstawie danych, używając wskazanej lub domyślnej palety */
    explicit AntRule(const std::vector<Direction> &directions, const AntRulePalette &palette = AntRulePalette());
    explicit AntRule(const std::string &directions, const AntRulePalette &palette = AntRulePalette());

    /* Dodaje nową parę na koniec reguły, używając wskazanego koloru bądź pobranego z domyślnej palety.
       Zwraca true, jeżeli dane są poprawne i (dla metod jednoargumentowych) dostępny jest kolor z palety, w wyniku czego uaktualniono regułę;
       false w przeciwnym wypadku.
     */
    bool appendPair(Direction dir);
    bool appendPair(Direction dir, const sf::Color &color);
    bool appendPair(const Pair &pair);
    bool appendPair(char direction);
    bool appendPair(char direction, const sf::Color &color);

    /* Dodaje pary na koniec reguły, używając odpowiednio kolorów z listy lub domyślnej palety.
     * Zwraca true, jeżeli całość możliwych danych jest poprawna i dostępne są kolory, w wyniku czego uaktualniono regułę;
     * false w przeciwnym wypadku
     */
    bool appendPairs(const std::vector<Pair> &pairs);
    bool appendPairs(const std::vector<Direction> &directions, const AntRulePalette &palette = AntRulePalette());
    bool appendPairs(const std::string &rules, const AntRulePalette &palette = AntRulePalette());

    /* Metody zwracające pojedyncze dane. position musi być prawidłowym indeksem, nie jest sprawdzana jego poprawność */
    const Pair & getPair(uint position) const;
    Direction getDirection(uint position) const;
    const sf::Color & getColor(uint position) const;
    char getPairChar(uint position) const;

    /* Długość reguły, czyli ilość przypisań */
    inline uint length() const;

    /* Tekstowa reprezentacja reguły */
    inline const std::string & toString() const;

    /* Zwraca true, jeżeli reguła nie jest pusta, w innym wypadku false */
    inline bool isValid() const;

    /* Porównuje reguły. Pary muszą być w tej samej kolejności i muszą być identyczne (zarówno kierunki jak i kolory) */
    bool operator==(const AntRule &rule) const;
    bool operator!=(const AntRule &rule) const;

    /* Domyślna reguła symulacji - "RL" */
    static const AntRule & defaultRule();

private:
    bool hasDefPaletteNextColor(uint position) const;
    const sf::Color & getDefPaletteNextColor(uint position) const;

    Direction charToDirection(char c, bool *ok) const;
    char directionToChar(Direction dir) const;

    std::vector<Pair> rule_data;
    std::string string_form;
};


inline const AntRule::Pair & AntRule::getPair(uint position) const
{ return rule_data.at(position); }

inline Direction AntRule::getDirection(uint position) const
{ return getPair(position).first; }

inline const sf::Color & AntRule::getColor(uint position) const
{ return getPair(position).second; }

inline char AntRule::getPairChar(uint position) const
{ return string_form.at(position); }

uint AntRule::length() const
{ return string_form.size(); }

const std::string & AntRule::toString() const
{ return string_form; }

bool AntRule::isValid() const
{ return length() > 0; }

inline bool AntRule::operator==(const AntRule &rule) const
{ return rule_data == rule.rule_data; }

inline bool AntRule::operator!=(const AntRule &rule) const
{ return !(*this == rule); }

inline bool AntRule::hasDefPaletteNextColor(uint position) const
{ return position < AntRulePalette::defaultPalette().size(); }

inline const sf::Color & AntRule::getDefPaletteNextColor(uint position) const
{ return AntRulePalette::defaultPalette().data().at(position); }

#endif // ANTRULE_H
