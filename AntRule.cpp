#include "AntRule.hpp"


AntRulePalette::AntRulePalette()
{ }

AntRulePalette::AntRulePalette(const std::vector<sf::Color> &colors_db)
    : colors(colors_db)
{ }

AntRulePalette::AntRulePalette(std::vector<sf::Color> &&colors_db)
{
    colors.swap(colors_db);
}

const AntRulePalette & AntRulePalette::defaultPalette()
{
    /** @todo Na pewno do zmiany w przyszłości na bardziej stonowane */
    static const AntRulePalette def_palette = AntRulePalette({
        sf::Color::White,
        sf::Color::Black,
        sf::Color::Red,
        sf::Color::Blue,
        sf::Color::Green,
        sf::Color::Yellow,
        sf::Color::Magenta,
        sf::Color::Cyan
    });

    return def_palette;
}

AntRule::AntRule()
{ }

AntRule::AntRule(const std::vector<Direction> &directions, const AntRulePalette &palette)
{
    appendPairs(directions, palette);
}

AntRule::AntRule(const std::string &directions, const AntRulePalette &palette)
{
    appendPairs(directions, palette);
}

bool AntRule::appendPair(Direction dir)
{
    uint next_pos = length();

    if (hasDefPaletteNextColor(next_pos))
        return appendPair({dir, getDefPaletteNextColor(next_pos)});

    return false;
}

bool AntRule::appendPair(Direction dir, const sf::Color &color)
{
    return appendPair({dir, color});
}

bool AntRule::appendPair(const AntRule::Pair &pair)
{
    char c = directionToChar(pair.first); // c jest zerem, jeżeli konwersja się nie powiodła

    if (c) {
        rule_data.push_back(pair);
        string_form.push_back(c);
    }

    return c;
}

bool AntRule::appendPair(char direction)
{
    uint next_pos = length();
    bool conversion = false;
    Direction dir = charToDirection(direction, &conversion);

    if (conversion && hasDefPaletteNextColor(next_pos))
        return appendPair({dir, getDefPaletteNextColor(next_pos)});

    return false;
}

bool AntRule::appendPair(char direction, const sf::Color &color)
{
    bool conversion = false;
    Direction dir = charToDirection(direction, &conversion);

    if (conversion)
        return appendPair({dir, color});

    return false;
}

bool AntRule::appendPairs(const std::vector<AntRule::Pair> &pairs)
{
    /* Zabezpieczam obecne dane */
    std::vector<Pair> previous_data;
    std::string previous_string;

    previous_data.swap(rule_data);
    previous_string.swap(string_form);

    bool result = true;

    for (const Pair &p : pairs) {
        if (!result)
            break;

        result &= appendPair(p);
    }

    if (result) {
        /* Powiodło się - dopisuję nowe dane do poprzednich */
        previous_data.insert(previous_data.end(), rule_data.begin(), rule_data.end());
        previous_string.insert(previous_string.end(), string_form.begin(), string_form.end());

        rule_data = previous_data;
        string_form = previous_string;
    } else {
        /* Nie powiodło się - przywracam stare dane */
        previous_data.swap(rule_data);
        previous_string.swap(string_form);
    }

    return result;
}

bool AntRule::appendPairs(const std::vector<Direction> &directions, const AntRulePalette &palette)
{
    uint palette_start_index = 0;
    uint palette_end_index = palette.size();

    /* Jeżeli używam domyślnej palety, muszę pamiętać, żeby kolory brać od aktualnego indeksu */
    if (palette.size() == 0) {
        palette_start_index = length();
        palette_end_index = AntRulePalette::defaultPalette().size();
    }

    if (palette_start_index > palette_end_index)
        palette_start_index = palette_end_index; // w celu uniknięcia liczb ujemnych

    /* Tylko dla części danych można stworzyć pary */
    uint to_append = std::min((uint) directions.size(), std::max((uint) 0, palette_end_index - palette_start_index));

    if (to_append == 0)
        return false;

    const AntRulePalette &palette_ref = palette.size() > 0 ? palette : AntRulePalette::defaultPalette();

    /* Przygotowuję te pary, które mogą zostać dodane */
    std::vector<Pair> new_pairs;
    new_pairs.reserve(to_append);

    uint i = 0;

    while (i < to_append) {
        new_pairs.push_back({directions.at(i), palette_ref.data().at(palette_start_index + i)});
        ++i;
    }

    return appendPairs(new_pairs);
}

bool AntRule::appendPairs(const std::string &rules, const AntRulePalette &palette)
{
    /* Konwertuję ciąg na listę kierunków, resztą zajmuje się bliźniacza metoda */

    std::vector<Direction> directions;
    directions.reserve(rules.size());

    Direction tmp_dir;
    bool ok; // ignoruję odczyty; wygoda implementacji, ale nie maksymalna wydajność

    for (uint i = 0; i < rules.size(); ++i) {
        tmp_dir = charToDirection(rules.at(i), &ok); // niewspierane kierunki zostaną później pominięte
        directions.push_back(tmp_dir);
    }

    return appendPairs(directions, palette);
}

const AntRule & AntRule::defaultRule()
{
    static const AntRule rule = AntRule("RL");
    return rule;
}

Direction AntRule::charToDirection(char c, bool *ok) const
{
    if (c == 'L' || c == 'l') {
        *ok = true;
        return Direction::Left;
    }

    if (c == 'R' || c == 'r') {
        *ok = true;
        return Direction::Right;
    }

    *ok = false;
    return Direction::Down; // cokolwiek niewspieranego
}

char AntRule::directionToChar(Direction dir) const
{
    char result = 0;

    if (dir == Direction::Left)
        result = 'L';
    else if (dir == Direction::Right)
        result = 'R';

    return result;
}
