#pragma once

#include <iostream>
#include <vector>
#include <algorithm> // std::sort
#include "Requirement.hpp"

class User
{
    /*
	  Класс пользователя
	  Создание пользователя:
		User имя пользователя(баланс(balance));
	  Добавление потребности пользователю:
		имя пользователя.add_requirement(имя объекта потребности);
		Например, user1.add_requirement(first);
	  Вызов потребности:
		имя пользователся.requirements[индекс потребности].имя переменной
		Например, user1.requirements[0].price
	*/
private:
    std::vector<Requirement> requirements_first_priority;
    std::vector<Requirement> requirements_second_priority;
    std::vector<Requirement> requirements_third_priority;
    std::vector<Requirement> requirements_fourth_priority;

    bool is_balance_upper()
    {
        return start_balance * 0.8 < balance;
    }

    bool cmp_first_priority(struct Requirement a, struct Requirement b)
    {
        double r1 = (double)a.duration_of_effect / (double)a.price;
        double r2 = (double)b.duration_of_effect / (double)b.price;
        return r1 < r2;
    }

public:
    int start_balance;
    int balance;
    std::vector<Requirement> requirements;

    User()
    {
        this->balance = 0;
    };

    User(int balance)
    {
        this->balance = balance;
    };

    void add_requirement(Requirement requirement)
    {
        this->requirements.push_back(requirement);
    }

    void calculation()
    {
        start_balance = balance;

        std::sort(requirements.begin(), requirements.end());

        for (size_t i = 0; i < requirements.size(); i++)
        {
            if (requirements[i].priority == 1)
                requirements_first_priority.push_back(requirements[i]);
            else if (requirements[i].priority == 2)
                requirements_second_priority.push_back(requirements[i]);
            else if (requirements[i].priority == 2)
                requirements_third_priority.push_back(requirements[i]);
            else
                requirements_fourth_priority.push_back(requirements[i]);
        }
        std::sort(requirements_first_priority.begin(),
                  requirements_first_priority.end(),
                  cmp_first_priority);
    }
};

std::ostream &operator<<(std::ostream &os, std::vector<Requirement> &req_list)
{
    for (auto req : req_list)
    {
        std::cout << req.name << std::endl;
        std::cout << "price: " << req.price << std::endl;
        std::cout << "priority: " << req.priority << std::endl;
        std::cout << "preference: " << req.preference << std::endl;
        std::cout << "duration_of_effect: " << req.duration_of_effect << std::endl;
    }
    return os;
}
