#include <iostream>
#include <algorithm>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#include <string>

char getRandomNumber(int min, int max) // Рандомное получение числа из заданного диапазона
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем рандомное число в нашем диапазоне
	return static_cast<char>(rand() * fraction * (max - min + 1) + min);
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	setlocale(LC_ALL, "rus"); // Русский язык в консоли 

	int m{}, user_choose{};
	std::string user_letter;

	do // Получение размеров массива от пользователя
	{
		std::cout << "Введите целочисленное число M (диапазона [2,5]), чтобы создать матрицу MxM: ";
		std::cin >> m;

		std::cin.ignore(32767, '\n');

		if (!(m >= 2 && m <= 5))
			std::cerr << "Ваше значение не подходит в данный диапазон, пожалуйста, повторите попытку" << std::endl;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}

	} while (!(m >= 2 && m <= 5));

	char** array = new char* [m] {};

	int* finish_array = new int[m] {};

	for (int count{}; count < m; count++)
		array[count] = new char[m] {};

	do // Выбор способа заполнения массива
	{
		std::cout << "Вы хотите сами заполнить строки? Если да, введите 1 |  Если нет, введите 2: ";
		std::cin >> user_choose;

		std::cin.ignore(32767, '\n');

		if (user_choose != 2 && user_choose != 1)
			std::cerr << "Ваше значение не подходит в данный диапазон, пожалуйста, повторите попытку" << std::endl;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}

	} while (user_choose != 2 && user_choose != 1);

	if (user_choose == 1) // Ручное заполнение массива
		for (int count1{}; count1 < m; count1++)
		{
			std::cout << "Введите " << count1 + 1 << " строку в двумерном массиве " << std::endl;

			for (int count2{}; count2 < m; count2++)
			{
				do
				{
					std::cout << count2 + 1 << " Буква(от A(a) до Z(z) в строке(Без пробелов): " << std::endl;;

					std::getline(std::cin, user_letter);

					if (static_cast<int>(user_letter[0]) < 65 || static_cast<int>(user_letter[0]) > 122)
					{
						std::cout << "Вы не ввели букву, пожалуйста, повторите попытку" << std::endl;
						std::cin.ignore(32767, '\n');
						user_letter.clear();
					}

					if ((user_letter.size() != 1))
					{
						std::cout << "Ваши данные некорректны(нужна одна буква)! " << std::endl;
						user_letter.clear();
					}
				} while (!(user_letter.size() == 1 && (static_cast<int>(user_letter[0]) >= 65 && static_cast<int>(user_letter[0]) <= 122)));

				array[count1][count2] = user_letter[0];
			}
		}

	else // Автоматическое заполнение массива
		for (int count1{}; count1 < m; count1++)
		{
			std::cout << "Автоматическое заполнение " << count1 + 1 << " строки" << std::endl;

			for (int count2{}; count2 < m; count2++)
			{
				array[count1][count2] = getRandomNumber(65, 90);

				std::cout << count2 + 1 << " Буква(от A(a) до Z(z) в строке: " << array[count1][count2] << std::endl;
			}
		}

	for (int count1{}; count1 < m; count1++) // Выполняем задание 
		for (int count2{}; count2 < m; count2++)
		{
			if (array[count1][count2] == 'A' || array[count1][count2] == 'E' || array[count1][count2] == 'I' ||
				array[count1][count2] == 'O' || array[count1][count2] == 'Y' || array[count1][count2] == 'a' ||
				array[count1][count2] == 'e' || array[count1][count2] == 'i' || array[count1][count2] == 'o' ||
				array[count1][count2] == 'y')
				finish_array[count1] += 10;

			else
				finish_array[count1] += 1;
		}

	for (int count1{}; count1 < m; count1++) // Выводим новую матрицу
		std::cout << count1 + 1 << " строка новой матрицы теперь равна: " << finish_array[count1] << std::endl;

	std::cout << "Сортировка массива! \n";

	for (int count1{ 1 }; count1 < m; count1++) // Пузырьковая сортировка
		if (finish_array[count1 - 1] > finish_array[count1])
			std::swap(finish_array[count1 - 1], finish_array[count1]);

	for (int count1{}; count1 < m; count1++) // Выводим отсортированную матрицу
		std::cout << count1 + 1 << " строка новой матрицы теперь равна: " << finish_array[count1] << std::endl;
}