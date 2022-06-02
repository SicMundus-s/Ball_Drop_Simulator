// Revesli_Chapter_6_Arrays.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> 
#include <algorithm> // для std::swap. В C++11 используйте заголовок <utility>
#include <string>

int main()
{
	const int length(9);
	int array[length] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
	//int twoLength = length;
	

	// Перебираем каждый элемент массива (кроме последнего, он уже будет отсортирован к тому времени, когда мы до него доберемся)
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		// В переменной smallestIndex хранится индекс наименьшего значения, которое мы нашли в этой итерации.
		// Начинаем с того, что наименьший элемент в этой итерации - это первый элемент (индекс 0)
		
		int twoLength = length;
		bool swapped(false); // отслеживаем, были ли выполнены замены в этой итерации


		
		for (int currentIndex = 0; currentIndex < twoLength - 1; ++currentIndex)
		{
			int counterIteration = 0;
			if (array[currentIndex] > array[currentIndex + 1])
			{
				swapped = true;
				std::swap(array[currentIndex], array[currentIndex + 1]);
			}

			
			
		}
		if (!swapped)
		{
			// Выполнение начинается с 0-й итерации, но мы привыкли считать, начиная с 1, поэтому для подсчета количества итераций добавляем единицу
			std::cout << "Early termination on iteration: " << startIndex + 1 << '\n';
			break;
		}

		--twoLength;

		for (int index = 0; index < length; ++index)
			std::cout << array[index] << ' ';
		std::cout << '\n';
	}

		
	

	// Теперь, когда весь массив отсортирован - выводим его на экран
	// for (int index = 0; index < length; ++index)
	//	std::cout << array[index] << ' ';

	return 0;
}