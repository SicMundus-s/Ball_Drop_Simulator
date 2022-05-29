#include <iostream>
#include "constant.h"

// Получаем начальную высоту от пользователя и возвращаем её
double getInitialHeight()
{
	
	do
	{
		std::cout << "Enter the initial height of the tower in meters: ";
		double initialHeight;
		std::cin >> initialHeight;

		if (std::cin.fail()) // если предыдущее извлечение не выполнилось или произошло переполнение,
		{
			std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			std::cout << "Repeat enter the number! \n ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return initialHeight;
		}
	} while (true);

	
	
}

// Возвращаем расстояние от земли после "..." секунд падения
void calculateHeight(double initialHeight)
{
	// Используем формулу: [ s = u * t + (a * t^2) / 2 ], где u(начальная скорость) = 0
	for (int seconds = 0; initialHeight > 0.0; seconds++)
	{
		double distanceFallen = (myConstants::gravity * seconds * seconds) / 2;
		double currentHeight = initialHeight - distanceFallen;

		if (currentHeight > 0.0)
		{
			std::cout << "At " << seconds << " seconds, the ball is at height:\t" << currentHeight <<
				" meters\n";
		}
		else
		{
			std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
			break;
		}
	}
	
	
}

int main()
{
	const double initialHeight = getInitialHeight();
	calculateHeight(initialHeight);
	return 0;
}