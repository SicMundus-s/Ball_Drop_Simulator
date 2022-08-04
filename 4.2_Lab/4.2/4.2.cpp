#include <iostream>

int search_sign(int user_value)
{
	if (user_value > 0)
		return 1;

	if (user_value < 0)
		return -1;

	if (user_value == 0)
		return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int user_value{};

	std::cout << "Введите значениe, чтобы определить его знак: ";
	std::cin >> user_value;

	std::cout << "Знак вашего числа равен: " << search_sign(user_value);

	return 0;
}