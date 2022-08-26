#include <iostream>
#include <vector>

int change_to_arabic_numerals(char roman_numeral)
{
	switch (roman_numeral)
	{
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	}
}

int change_numeral(std::vector<char> roman_numeral_array)
{
	int arabic_system{}, first_value{}, second_value{};

	for (int count{}; count < roman_numeral_array.size(); count++)
	{
		if (count == 0)
			arabic_system = change_to_arabic_numerals(roman_numeral_array[count]);

		else if (change_to_arabic_numerals(roman_numeral_array[count - 1]) == change_to_arabic_numerals(roman_numeral_array[count]))
			arabic_system += change_to_arabic_numerals(roman_numeral_array[count - 1]);

		else if (change_to_arabic_numerals(roman_numeral_array[count - 1]) < change_to_arabic_numerals(roman_numeral_array[count]))
		{
			arabic_system -= change_to_arabic_numerals(roman_numeral_array[count - 1]);
			arabic_system += change_to_arabic_numerals(roman_numeral_array[count]) - change_to_arabic_numerals(roman_numeral_array[count - 1]);
		}

		else if (change_to_arabic_numerals(roman_numeral_array[count - 1]) > change_to_arabic_numerals(roman_numeral_array[count]))
			arabic_system += change_to_arabic_numerals(roman_numeral_array[count]);
	}
	return arabic_system;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int length{};

	std::cout << "Сколько вы хотите ввести символов? ";
	std::cin >> length;

	std::vector<char> roman_numeral_array{};
	roman_numeral_array.resize(length);

	std::cout << "Введите ваше значение в римской системе счисления: ";

	for (int count{}; count < length; count++)
		std::cin >> roman_numeral_array[count];

	std::cout << "Ваше значение в арабской системе счисления: " << change_numeral(roman_numeral_array);
}