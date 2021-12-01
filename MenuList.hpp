#pragma once

#include "MenuOptions.hpp"

namespace menu
{
    menu_options_t options = {{{"Input your balance",
                                [](User &user)
                                {
                                    std::cout << "Input new balance: ";
                                    std::cin >> user.balance;
                                }},
                               {"Add new requirement",
                                [](User &user)
                                {
                                    user.add_requirement(create_requirement());
                                }},
                               {"Show all requirements",
                                [](User &user)
                                {
                                    user.print_requirements();
                                }},
                               {"Result",
                                [](User &user)
                                {
                                    user.calculation();
                                }}}};

    //*example *
    /*
    menu_options_t menu2 = {
        {"option1",
         [](User &user)
         {
             do_stuff();
         }}};
    */
}