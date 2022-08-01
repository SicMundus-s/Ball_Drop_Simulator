#include <iostream>
#include <fstream>
#include <string>

int main()
{
	setlocale(LC_ALL, "rus");

	std::ofstream output_current_file{ "Test.txt" };
	int sum{}, part{};

	output_current_file << "1 2 3 4 5 6 7 8 9 1";
	output_current_file.close();

	std::ifstream input_current_file;
	input_current_file.open("Test.txt");

	while (input_current_file >> part)
		sum += part;

	std::cout << "Сумма чисел равна: " << sum;
}