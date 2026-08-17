#include "helper.hpp"

int main()
{
    std::vector<Player> players;
    populate(players, 8, 1000.0, 150);
    print_population_stats(players);
    auto initial_bracket = make_initial_layer(players);
    auto next_layer = get_next_layer(initial_bracket);
}
