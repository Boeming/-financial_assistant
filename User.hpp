#pragma once

#include <iostream>
#include <vector>

#include "Requirement.hpp"

class User
{
    /*
	  Класс пользователя
	  Создание пользователя:
		User имя пользователя(баланс(balance));
	  Добавление потребности пользователю:
		имя пользователя.addRequirement(имя объекта потребности);
		Например, user1.addRequirement(first);
	  Вызов потребности:
		имя пользователся.requirements[индекс потребности].имя переменной
		Например, user1.requirements[0].price
	*/
private:
    //функция "если остаток меньше\больше 80%
    bool is_balance_upper()
    {
        return start_balance * 0.8 < balance;
    }

public:
    int start_balance;
    int balance;
    std::vector<Requirement> requirements;

    User(int balance)
    {
        this->balance = balance;
    };

    void add_requirement(Requirement requirement)
    {
        this->requirements.push_back(requirement);
    }

    //функция для вывода всех потребностей
    void print_requirements()
    {
        for (auto req : requirements)
        {
            std::cout << req.name << std::endl;
            std::cout << "price: " << req.price << std::endl;
            // ...
        }
    }

    void calculation()
    {
        start_balance = balance;

        for (auto req : requirements)
        {
            if (req.priority == 1)
            {
            }
        }
    }
};