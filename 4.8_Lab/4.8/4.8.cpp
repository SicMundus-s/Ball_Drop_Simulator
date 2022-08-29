#include <iostream>

void most_sales_money(double total[3][2]) // Больше всего денег с продаж
{
	if (total[0][0] > total[1][0] && total[0][0] > total[2][0])
		std::cout << "Первый продавец выручил больше всего денег с продаж ";

	else if (total[1][0] > total[0][0] && total[1][0] > total[2][0])
		std::cout << "Второй продавец выручил больше всего денег с продаж \n";

	else
		std::cout << "Третий продавец выручил больше всего денег с продаж";
}

void least_of_all_sales_money(double total[3][2]) // Меньше всего денег с продаж
{
	if (total[0][0] < total[1][0] && total[0][0] < total[2][0])
		std::cout << "Первый продавец выручил меньше всего денег с продаж";

	else if (total[1][0] < total[0][0] && total[1][0] < total[2][0])
		std::cout << "Второй продавец выручил меньше всего денег с продаж";

	else
		std::cout << "Третий продавец выручил меньше всего денег с продаж \n";
}

void highest_commissions(double total[3][2]) // Наибольшие комиссионные с продаж
{
	if (total[0][1] > total[1][1] && total[0][1] > total[2][1])
		std::cout << "Первый продавец выручил больше всего комиссионных с продаж \n";

	else if (total[1][1] > total[0][1] && total[1][1] > total[2][1])
		std::cout << "Второй продавец выручил больше всего комиссионных с продаж ";

	else
		std::cout << "Третий продавец выручил больше всего комиссионных с продаж ";
}

void lowest_commission(double total[3][2]) // Наименьшие комиссионные с продаж
{
	if (total[0][1] < total[1][1] && total[0][1] < total[2][1])
		std::cout << "Первый продавец выручил больше всего комиссионных с продаж ";

	else if (total[1][1] < total[0][1] && total[1][1] < total[2][1])
		std::cout << "Второй продавец выручил больше всего комиссионных с продаж ";

	else
		std::cout << "Третий продавец выручил больше всего комиссионных с продаж \n";
}

int main()
{
	setlocale(LC_ALL, "rus");

	double total_amount_of_money{}, total_amount_of_commission{};

	double total[3][2]{};

	double A[3][4]
	{
		{5, 2, 0, 10},
		{3, 5, 2, 5},
		{20, 0, 0, 0}
	};

	double B[4][2]
	{
		{1.2, 0.5},
		{2.8, 0.4},
		{5.0, 1.0},
		{2.0, 1.5}
	};

	for (int count2{}; count2 < 3; count2++) // Умножение матриц
		for (int count3{}; count3 < 4; count3++)
		{
			total[count2][0] += A[count2][count3] * B[count3][0];
			total[count2][1] += A[count2][count3] * B[count3][1];
		}

	most_sales_money(total);
	least_of_all_sales_money(total);
	highest_commissions(total);
	lowest_commission(total);


	for (int count{}, count1{}; count < 3; count++) // Общая сумма денег
		total_amount_of_money += total[count][count1];

	for (int count{}, count1{ 1 }; count < 3; count++) // Общая сумма комиссионных
		total_amount_of_commission += total[count][count1];

	std::cout << "Общая сумма денег, вырученных за проданные товары: " << total_amount_of_money << std::endl;
	std::cout << "Общая сумма комиссионных: " << total_amount_of_commission << std::endl;
	std::cout << "Общая сумма денег, прошедших через руки продавцов: " << total_amount_of_commission + total_amount_of_money;
}