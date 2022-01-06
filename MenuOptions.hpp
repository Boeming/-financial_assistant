#include "options.hpp"
#include <array>

class MenuOptionProp
{
public:
    MenuOptionProp(const char *name, void (*p_func)(User *))
        : name(name), p_call(p_func)
    {
    }

    const char *name;
    void (*p_call)(User *);
};

class MenuOption
{
    User *user;
    MenuOptionProp *prop;

public:
    MenuOption(User *user) : user(user) {}
    void operator=(MenuOptionProp *prop)
    {
        this->prop = prop;
    }

    void call() const
    {
        (*(prop->p_call))(user);
    }
};

const int MENU_SIZE = 4;
std::array<MenuOptionProp, MENU_SIZE> option_list = {
    MenuOptionProp{"input balance", options::input_balance},
    {"add requirement", options::add_req},
    {"print requirements", options::print_reqs},
    {"result", options::calc_result},
};