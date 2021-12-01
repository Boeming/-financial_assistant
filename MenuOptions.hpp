#pragma once

#include <functional>

#include "User.hpp"

struct Option
{
    const char *name;
    std::function<void(User &)> function;
};

using menu_options_t = std::vector<Option>;