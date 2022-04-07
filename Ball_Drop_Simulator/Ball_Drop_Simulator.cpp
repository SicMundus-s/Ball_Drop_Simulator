#include <iostream>
#include "constants.h" // Подключение сообственных констант 

double towerHeight() // Запрашиваем высоту башни 
{
	std::cout << "Введитие высоту башни: ";
	double towerHeight; std::cin >> towerHeight;
	return towerHeight;
}
double result(int towerHeight, int secondTwo)
{


	double formula = (constants::my_gravity * secondTwo * secondTwo) / 2; // constants::my_gravity = 9.8
	double result = towerHeight - formula;

	if (result > 0.0)
		std::cout << "At " << secondTwo << " seconds, the ball is at height: " << result << " meters\n";
	else
		std::cout << "At " << secondTwo << " seconds, the ball is on the ground.\n";

	return result;


}

int main()
{

	setlocale(LC_ALL, "rus");

	const int towerHeightTwo = towerHeight();

	result(towerHeightTwo, 1);
	result(towerHeightTwo, 2);
	result(towerHeightTwo, 3);
	result(towerHeightTwo, 4);
	result(towerHeightTwo, 5);
	result(towerHeightTwo, 6);
	result(towerHeightTwo, 7);
	result(towerHeightTwo, 8);
	result(towerHeightTwo, 9);
	result(towerHeightTwo, 10);

	return 0;



}