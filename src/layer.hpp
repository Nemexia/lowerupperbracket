#pragma once
#include <vector>

#include "match.hpp"

struct Layer
{
    std::vector<Match> upper_bracket;
    std::vector<Match> lower_bracket;
};