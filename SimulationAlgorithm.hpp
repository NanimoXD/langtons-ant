#ifndef SIMULATIONALGORITHM_H
#define SIMULATIONALGORITHM_H

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
    inline void setRule(const AntRule &rule);
    inline const AntRule & rule() const;

    /* Przypisuje planszę, robiąc jej kopię */
    void setBoard(const Board &b);

    /* Przypisuje planszę, przejmując jej dane. Plansza będąca parametrem zostanie wyczyszczona */
    void takeBoard(Board &b);

    /* Dostęp do planszy */
    inline Board & board();
    inline const Board & board() const;

    /* Dostęp i zmiana licznika tury */
    void setTurn(unsigned int t);
    inline unsigned int turn() const;
    void resetTurnCounter();

    /* Czy klasa ma wszystkie dane potrzebne do przeprowadzenia symulacji i są one poprawne */
    bool canSimulate() const;

    /* Przeprowadza symulację na aktualnych danych do następnej tury.
     * Jeżeli plansza jest za mała, zostanie rozszerzona.
     *
     * Działania składające się na jedną turę:
     * 1. Zmiana koloru w miejscu, gdzie aktualnie jest mrówka.
     * 2. Zmiana kierunku według reguły na podstawie koloru pierwotnego.
     * 3. Wykonanie kroku mrówki do następnego pola.
     */
    void simulate();

private:
    AntRule ant_rule;
    Board sim_board;
    unsigned int turn_num;
};

void SimulationAlgorithm::setRule(const AntRule &rule)
{ ant_rule = rule; }

const AntRule & SimulationAlgorithm::rule() const
{ return ant_rule; }

inline void SimulationAlgorithm::setBoard(const Board &b)
{ sim_board = b; }

inline void SimulationAlgorithm::takeBoard(Board &b)
{ Board b_empty; b_empty.swap(b); sim_board.swap(b_empty); }

Board & SimulationAlgorithm::board()
{ return sim_board; }

const Board & SimulationAlgorithm::board() const
{ return sim_board; }

inline void SimulationAlgorithm::setTurn(unsigned int t)
{ turn_num = t; }

unsigned int SimulationAlgorithm::turn() const
{ return turn_num; }

inline void SimulationAlgorithm::resetTurnCounter()
{ turn_num = 0; }

#endif // SIMULATIONALGORITHM_H
