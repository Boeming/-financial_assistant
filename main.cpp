#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include "Requirement.hpp"
#include "MenuOptions.hpp"
#include "User.hpp"

#include "MenuList.hpp"

int main_menu()
{
	User user(0);

	while (1)
	{
		std::cout << "Your balance: " << user.balance << std::endl;

		for (int i = 0; i < menu::options.size(); i++)
		{
			std::cout << i + 1 << ' ' << menu::options[i].name << std::endl;
		}

		int choice;
		std::cin >> choice;

		menu::options[choice - 1].function(user);
	}
}

int main()
{
	main_menu();
}
