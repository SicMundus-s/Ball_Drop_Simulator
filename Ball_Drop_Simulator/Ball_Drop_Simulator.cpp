#include <iostream>
#include "constants.h" // Подключение сообственных констант 

double towerHeight() // Запрашиваем высоту башни 
{
	std::cout << "Введитие высоту башни: ";
	double towerHeight; std::cin >> towerHeight;
	return towerHeight;
}
/// <summary>
/// 
/// </summary>
/// <param name="towerHeight"></param>
/// <param name="secondTwo"></param>
/// <returns></returns>
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

void feature()
{
	std::cout << "feature\n";
}
/// <summary>
/// 
/// </summary>
/// <returns></returns>

int main()
{

	setlocale(LC_ALL, "rus");

	const int towerHeightTwo = towerHeight();

	result(towerHeightTwo, 101);
	

	std::cout << "HelloGit";

	feature();
	feature();


	return 0;



}