#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");

	int N{};

	std::cout << "Введите конечное число N, до которого будут найдены все натуральные числа: ";
	std::cin >> N;

	int* start_array = new int[N - 1]; // Минус один, так как не учитываем 1

	for (int count{}; count < N - 1; count++) // Присваем массиву числа до N(включительно)
	{
		start_array[count] = count + 2;
	}

	for (int index{}, count{ 2 }; count < N - 1; count++, index++) // Решето Эратосфена
		for (int array_count{ index }; array_count < N - 1; array_count += count)
			if (start_array[array_count] == count)
				continue;
			else
				start_array[array_count] = 0;

	std::cout << "Натуральные числа: ";

	for (int count{}; count < N - 1; count++)
		if (start_array[count] != 0)
			std::cout << start_array[count] << " ";
}