#include <iostream>

double calculate_area_triangle(double user_triangle_a, double user_triangle_h)
{
	return 0.5 * user_triangle_a * user_triangle_h;
}

double calculate_area_rectangle(double user_rectangle_a, double user_rectangle_b)
{
	return user_rectangle_a * user_rectangle_b;
}

double calculate_area_circle(double user_circle_r)
{
	return 3.14 * user_circle_r * user_circle_r;
}

int main()
{
	setlocale(LC_ALL, "rus");

	double triangle_a{};
	double triangle_h{};

	double rectangle_a{};
	double rectangle_b{};

	double circle_r{};


	std::cout << "Введите высоту и основание треугольника, чтобы рассчитать его площадь " << std::endl;
	std::cin >> triangle_h;
	std::cin >> triangle_a;

	std::cout << "Введите длину и ширину прямоугольника, чтобы рассчитать его площадь " << std::endl;;
	std::cin >> rectangle_a;
	std::cin >> rectangle_b;

	std::cout << "Введите радиус окружности, чтобы рассчитать ее площадь " << std::endl;;
	std::cin >> circle_r;

	if (triangle_a < 0 || triangle_h < 0)
		std::cout << "Данные введены некорректно" << std::endl;
	else
		std::cout << "Площадь треугольника равна: " << calculate_area_triangle(triangle_a, triangle_h) << std::endl;

	if (rectangle_a < 0 || rectangle_b < 0)
		std::cout << "Данные введены некорректно" << std::endl;
	else
		std::cout << "Площадь прямоугольника равна: " << calculate_area_rectangle(rectangle_a, rectangle_b) << std::endl;

	if (circle_r < 0)
		std::cout << "Данные введены некорректно" << std::endl;
	else
		std::cout << "Площадь круга равна: " << calculate_area_circle(circle_r) << std::endl;
}