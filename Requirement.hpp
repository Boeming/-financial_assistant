#pragma once

#include <iostream>
#include <string>

struct Requirement
{
    /*
	Структура потребности
	Создание одной потребности:
		Requirement название потребности(название(name),
										цена(price),
										важность(priority),
										предпочтительность(preference),
										длительность эффекта(duration_of_effect));
	Обращение к элементам потребности:
		название потребности.имя переменной
		Например, first.price;
	*/

    std::string name;
    int price, priority, preference, duration_of_effect;

    Requirement(){};

    Requirement(std::string name, int price,
                int priority, int preference,
                int duration_of_effect)
    {
        this->name = name;
        this->price = price;
        this->priority = priority;
        this->preference = preference;
        this->duration_of_effect = duration_of_effect;
    };

    bool operator<(Requirement &other)
    {
        if (this->priority == other.priority)
        {
            if (this->price == other.price)
            {
                if (this->duration_of_effect == other.duration_of_effect)
                    return !(other.preference < this->preference);
                return !(this->duration_of_effect < other.duration_of_effect);
            }
            return !(this->price < other.price);
        }
        else
            return !(this->priority < other.priority);
    }
};

Requirement create_requirement()
{
    Requirement req;

    std::cin >> req.name;
    std::cin >> req.price;
    std::cin >> req.priority;
    std::cin >> req.preference;
    std::cin >> req.duration_of_effect;
    return req;
}