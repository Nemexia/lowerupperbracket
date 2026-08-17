#include "helper.hpp"

#include <algorithm>
#include <iostream>
#include <random>

void populate(std::vector<Player>& players, const int count, const double mean, const double stddev)
{
    players.reserve(count);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> distribution(mean, stddev);

    for (int i = 0; i < count; i++)
    {
        players.emplace_back(distribution(gen));
    }
}

double win_probability(const Player& player_one, const Player& player_two)
{
    constexpr double scale = 400.0;

    const double power_difference = player_one.power - player_two.power;

    return 1.0 / (1.0 + std::pow(10.0, -power_difference / scale));
}

void print_population_stats(const std::vector<Player>& players)
{
    auto comp = [](const Player& a, const Player& b) { return a.power < b.power; };

    const auto min_player = *std::ranges::min_element(players, comp);
    const auto max_player = *std::ranges::max_element(players, comp);
    const auto range = max_player.power - min_player.power;
    const auto max_player_win_chance = win_probability(max_player, min_player);
    const auto max_player_win_ratio = max_player_win_chance / (1 - max_player_win_chance);

    std::cout << "Min: " << min_player.power << std::endl;
    std::cout << "Max: " << max_player.power << std::endl;
    std::cout << "Range: " << range << " with win probability: " << max_player_win_chance << " *"
              << max_player_win_ratio << std::endl;
}

Layer make_initial_layer(std::vector<Player>& players)
{
    Layer layer;
    layer.upper_bracket.reserve(players.size() / 2);

    for (int i = 0; i < players.size(); i += 2)
    {
        layer.upper_bracket.emplace_back(&players[i], &players[i + 1]);
    }

    return layer;
}

Layer get_next_layer(Layer& this_layer)
{
    Layer next_layer;
    next_layer.upper_bracket.resize(this_layer.upper_bracket.size() / 2);
    next_layer.lower_bracket.resize(this_layer.upper_bracket.size() / 2);

    for (int i = 0; i < this_layer.upper_bracket.size(); ++i)
    {
        this_layer.upper_bracket[i].winner_match = &next_layer.upper_bracket[i / 2];
        this_layer.upper_bracket[i].loser_match = &next_layer.lower_bracket[i / 2];
        this_layer.lower_bracket[i].winner_match = &next_layer.lower_bracket[i / 2];
    }

    return next_layer;
}
