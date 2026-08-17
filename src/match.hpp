#pragma once
#include "player.hpp"

struct Match
{
    Player* player_a;
    Player* player_b;
    Match* winner_match;
    Match* loser_match;
};