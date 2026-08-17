#pragma once
#include <vector>

#include "layer.hpp"
#include "player.hpp"

void populate(std::vector<Player>& players, const int count, const double mean, const double stddev);

double win_probability(const Player& player_one, const Player& player_two);

void print_population_stats(const std::vector<Player>& players);

Layer make_initial_layer(std::vector<Player>& players);

Layer get_next_layer(const Layer& layer);