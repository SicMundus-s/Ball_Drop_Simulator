#include <cstring> // для функции strlen
#include <iostream>
#include <typeinfo>
#include <string>
#include <algorithm> // для std::swap. В C++11 используйте заголовок <utility>


void sort(std::string* array, int length)
{

		// Перебираем каждый элемент массива (кроме последнего, он уже будет отсортирован к тому времени, когда мы до него доберемся)
		for (int startIndex = 0; startIndex < length - 1; ++startIndex)
		{
			// В переменной smallestIndex хранится индекс наименьшего значения, которое мы нашли в этой итерации.
			// Начинаем с того, что наименьший элемент в этой итерации - это первый элемент (индекс 0)
			int smallestIndex = startIndex;

			// Затем ищем элемент поменьше в остальной части массива
			for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
			{
				// Если мы нашли элемент, который меньше нашего наименьшего элемента,
				if (array[currentIndex] < array[smallestIndex])
					// то запоминаем его
					smallestIndex = currentIndex;
			}

			// smallestIndex теперь наименьший элемент. 
			// Меняем местами наше начальное наименьшее число с тем, которое мы обнаружили
			std::swap(array[startIndex], array[smallestIndex]);
		}


		// Теперь, когда весь массив отсортирован - выводим его на экран
		std::cout << "Here is your sorted list: " << '\n';
		for (int index = 0; index < length; ++index)
		{
			std::cout << "Name #" << index + 1 << ": " << array[index] << '\n';
			
		}
		
}


int main()
{
    std::cout << "How many name would you like to enter?: ";
    int length; std::cin >> length; // Пользовательский ввод колличества имён
	std::cin.ignore(32767, '\n'); 
    std::string* array = new std::string[length];

    for (int count = 0; count < length; ++count)
    {
        std::cout << "Enter name #" << count + 1 << ": ";
        std::cin >> array[count];
    }
    
	sort(array, length);

	delete[] array;
	array = nullptr;

    return 0;
}
