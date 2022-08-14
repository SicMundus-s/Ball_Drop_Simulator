#include <iostream>

int main()
{
	char star{ '*' }, strip{ '-' };
	int value{};

	for (int count{}; count < 48; count += 8, std::cout << std::endl) // Выводим 48 звезд и 6 полос
		for (int count1{}; count1 < 24; count1++)
		{
			if (count1 < 8) // после 8 звезд выводим 16 -
				std::cout << star;
			else
				std::cout << strip;
		}

	for (int count{}; count < 168; count += 16, std::cout << std::endl) // Выводим оставшиеся 7 полос
		for (int count1{}; count1 < 24; count1++)
			std::cout << strip;
}