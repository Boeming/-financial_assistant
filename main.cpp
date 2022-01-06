#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>

#include "Requirement.hpp"
#include "User.hpp"
#include "MenuOptions.hpp"

// /* options.h */

// // include юзера

// namespace options
// {
// 	void input_balance(User *user)
// 	{
// 		std::cout << "Input new balance: ";
//         std::cin >> user.balance;
// 	}

// 	void add_req(User *user)
// 	{
// 		user.add_requirement(create_requirement());
// 	}

// 	void print_reqs(User *user)
// 	{
// 		std::cout << user.requirements;
// 	}

// 	void calc_result(User *user)
// 	{
// 		user.calculation();
// 	}
// }

// /* MenuOption.h */

// // не забудь #include "options.h" и все такое

// class MenuOptionProp
// {
// public:
// 	MenuOptionProp(const char *name, void (*p_func)(User *))
// 		: name(name), p_call(p_func)
// 	{
// 	}

// 	const char *name;
// 	void (*p_call)(User *);
// };

// class MenuOption
// {
// public:
// 	MenuOption(User *user) : user(user) {}
// 	void operator=(MenuOptionProp *prop)
// 	{
// 		this->prop = prop;
// 	}

// 	void call() const
// 	{
// 		(*(prop->p_call))(user);
// 	}

// private:
// 	User *user;
// 	MenuOptionProp *prop;
// };

// const int MENU_SIZE = 4;
// std::array<MenuOptionProp, MENU_SIZE> option_list = {
// 	MenuOptionProp{"input balance", options::input_balance},
// 	{"add requirement", options::add_req},
// 	{"print requirements", options::print_reqs},
// 	{"result", options::calc_result},
// };

/* main.cpp */

int main_menu()
{
	User user;
	MenuOption opt = &user;

	while (1)
	{
		std::cout << "Your balance: " << user.balance << std::endl;

		for (size_t i = 0; i < option_list.size(); i++)
		{
			std::cout << i + 1 << ' ' << option_list[i].name << std::endl;
		}

		int choice;
		std::cin >> choice;

		opt = &option_list[choice - 1];
		opt.call();
	}
}

int main()
{
	main_menu();
}