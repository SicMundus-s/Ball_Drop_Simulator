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
		// � ���������� smallestIndex �������� ������ ����������� ��������, ������� �� ����� � ���� ��������.
		// �������� � ����, ��� ���������� ������� � ���� �������� - ��� ������ ������� (������ 0)
		int smallestIndex = startIndex;

		// ����� ���� ������� �������� � ��������� ����� �������
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// ���� �� ����� �������, ������� ������ ������ ����������� ��������,
			if (student[currentIndex].grade > student[smallestIndex].grade)
				// �� ���������� ���
				smallestIndex = currentIndex;
				
		}

		// smallestIndex ������ ���������� �������. 
		// ������ ������� ���� ��������� ���������� ����� � ���, ������� �� ����������
		 std::swap(student[startIndex], student[smallestIndex]);
	}

	// ������, ����� ���� ������ ������������ - ������� ��� �� �����
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