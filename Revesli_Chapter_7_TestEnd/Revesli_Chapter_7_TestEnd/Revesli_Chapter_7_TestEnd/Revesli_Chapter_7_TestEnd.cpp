#include <iostream>
#include <array>
#include <vector>
#include <string>
// array - это массив, в котором мы проводим поиски.
// target - это искомое значение.
// min - это индекс минимальной границы массива, в котором мы осуществляем поиск.
// max - это индекс максимальной границы массива, в котором мы осуществляем поиск.
// Функция binarySearch() должна возвращать индекс искомого значения, если он обнаружен. В противном случае, возвращаем -1
int binarySearch(int* array, int target, int min, int max)
{
	int index = 0;
	while (min <= max)
	{
		index = min + ((max - min) / 2);
		if (array[index] > target)
			return binarySearch(array, target, min, max = index - 1);
		else if (array[index] < target)
			return binarySearch(array, target, min = index + 1, max);
		else 	
			return index;
			
		
	}
	return -1;
		

}

int main()
{
	int array[] = { 4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50 };

	std::cout << "Enter a number: ";
	int x;
	std::cin >> x;

	int index = binarySearch(array, x, 0, 14);

	std::string hh = "hhh";

	std::cout << index;

	if (array[index] == x)
		std::cout << "Good! Your value " << x << " is on position " << index << " in array!\n";
	else
		std::cout << "Fail! Your value " << x << " isn't in array!\n";
	return 0;
}