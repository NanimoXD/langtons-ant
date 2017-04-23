#include "SimulationAlgorithm.hpp"


SimulationAlgorithm::SimulationAlgorithm()
{
    ant_rule = AntRule::defaultRule();
    turn_num = 0;
    sim_board.resize(sf::Vector2u(1, 1));
    sim_board.setAntPosition(sf::Vector2u(0, 0));
}

bool SimulationAlgorithm::canSimulate() const
{
    /* Mrówka nie może istnieć na pustej planszy, dlatego nie sprawdzam rozmiaru */
    return ant_rule.isValid() && sim_board.hasAnt();
}

void SimulationAlgorithm::simulate()
{
    // todo
}
