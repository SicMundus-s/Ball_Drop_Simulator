/*#include <iostream>
#include <string>

struct Students
{
	std::string name;
	int grade = 0;
};

void sort(Students* student, int length)
{
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		// ¬ переменной smallestIndex хранитс€ индекс наименьшего значени€, которое мы нашли в этой итерации.
		// Ќачинаем с того, что наименьший элемент в этой итерации - это первый элемент (индекс 0)
		int smallestIndex = startIndex;

		// «атем ищем элемент поменьше в остальной части массива
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// ≈сли мы нашли элемент, который больше нашего наименьшего элемента,
			if (student[currentIndex].grade > student[smallestIndex].grade)
				// то запоминаем его
				smallestIndex = currentIndex;
				
		}

		// smallestIndex теперь наибольший элемент. 
		// ћен€ем местами наше начальное наименьшее число с тем, которое мы обнаружили
		 std::swap(student[startIndex], student[smallestIndex]);
	}

	// “еперь, когда весь массив отсортирован - выводим его на экран
	for (int index = 0; index < length; ++index)
		std::cout << student[index].name << " got a grade - " << student[index].grade << '\n';
}

void sortTwo(Students* student, int length, int &value)
{
	for (int startIndex = 0; startIndex < length - 1; startIndex++)
		for (int lastIndex = 0; lastIndex < length; lastIndex++)
		{
			if (student[startIndex].grade > student[lastIndex].grade)
			{
				value = student[startIndex].grade;
				student[startIndex].grade = student[lastIndex].grade;
				student[lastIndex].grade = value;
			}
		}

	for (int index = 0; index < length; ++index)
		std::cout << student[index].name << " got a grade - " << student[index].grade << '\n';
	
}

int main()
{
	
	std::cout << "How many students do you want to enter?: ";
	int length; std::cin >> length;
	Students* student = new Students[length];
	for (int index = 0; index < length; ++index)
	{

		std::cout << "Enter name #"  << index + 1 << ": ";
		std::cin >> student[index].name;
		std::cout << "Enter grade #" << index + 1 << ": ";
		std::cin >> student[index].grade;
	}
	sort(student, length);

	int value = 0;
	sortTwo(student, length, value);

}
*/