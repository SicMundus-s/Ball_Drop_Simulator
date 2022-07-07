#include <iostream>
#include <cstdlib>

void chek_values(int value1, int value2)
{
	if (value1 <= 0 || value2 <= 0)
	{
		std::cout << "Ваши значения не являются натуральными числами";
		exit(2);
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	int value1{}, value2{}, greatest_common_factor{};

	std::cout << "Последовательно введите первое и второе значение: \n";
	std::cin >> value1;
	std::cin >> value2;

	chek_values(value1, value2); // Проверка значений пользователя (являются ли натуральными)

	while (value1 != value2 && value1 != 0 && value2 != 0) // Цикл: из наибольшего значения отнимаем наименьшее(Алгоритм Евклида)
	{
		if (value1 > value2)
			value1 -= value2;
		else
			value2 -= value1;
	}

	if (value1 = value2)
		greatest_common_factor = value1;

	else if (value1 == 0)
		greatest_common_factor = value2;

	else
		greatest_common_factor = value1;

	std::cout << "НОД двух значений равен: " << greatest_common_factor;
}