#ifndef SIMULATIONALGORITHM_H
#define SIMULATIONALGORITHM_H

#include "Ant.hpp"
#include "AntRule.hpp"
#include "Board.hpp"

/* Klasa przeprowadzająca proces symulacji */

class SimulationAlgorithm
{
public:
    /* Konstruuje z domyślnej reguły, tury 0 oraz planszy, na której jest tylko mrówka.
     * canSimulate() zwraca true.
     */
    SimulationAlgorithm();

    /* Dostęp do reguły symulacji */
    void setRule(const AntRule &rule);
    const AntRule & rule() const;

    /* Przypisuje planszę, robiąc jej kopię */
    void setBoard(const Board &b);

    /* Przypisuje planszę, przejmując jej dane. Plansza będąca parametrem zostanie wyczyszczona */
    void takeBoard(Board &b);

    /* Dostęp do planszy */
    Board & board();
    const Board & board() const;

    /* Dostęp i zmiana licznika tury */
    void setTurn(unsigned int t);
    unsigned int turn() const;
    void resetTurnCounter();

    /* Czy klasa ma wszystkie dane potrzebne do przeprowadzenia symulacji i są one poprawne */
    bool canSimulate() const;

    /* Przeprowadza symulację na aktualnych danych do następnej tury.
     * Jeżeli plansza jest za mała, zostanie rozszerzona.
     */
    void simulate();

private:
    Ant ant;
    AntRule ant_rule;
    Board sim_board;
    unsigned int turn_num;
};

#endif // SIMULATIONALGORITHM_H
