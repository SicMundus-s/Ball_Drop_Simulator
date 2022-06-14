
#include <iostream> 
#include <cassert>
#include <cstdint>
#include <cmath>

class FixedPoint
{
private:
	std::int16_t m_base;
	std::int8_t m_fractional;
public: 
	FixedPoint(std::int16_t base = 0, std::int8_t fractional = 0) : m_base(base), m_fractional(fractional) // Конвертитровать и потом прибавить к основному
	{
		if (m_base < 0.0 || m_fractional < 0.0)
		{
			// Проверяем целую часть
			if (m_base > 0.0)
				m_base = -m_base;
			// Проверяем дробную часть
			if (m_fractional > 0.0)
				m_fractional = -m_fractional;
		}
			
	};


	FixedPoint(double based)
	{
		m_base = static_cast<std::int16_t>(based);
		m_fractional = static_cast<std::int8_t>(round((based - m_base) * 100));
		

	}

	operator double() const
	{
		return m_base + static_cast<double>(m_fractional) / 100;
	}


	friend std::ostream& operator<<(std::ostream& out,const FixedPoint& p) 
	{
		out << static_cast<double>(p);
		return out;
	}

	friend std::istream& operator >> (std::istream& in, FixedPoint& p)
	{
		double d;
		in >> d;
		p = FixedPoint(d);
		return in;
	}

	friend FixedPoint operator+(FixedPoint& p1, FixedPoint& p2)
	{
		return FixedPoint(static_cast<double>(p1) + static_cast<double>(p2));
	}

	friend FixedPoint operator ==(FixedPoint& p1, FixedPoint& p2)
	{
		return FixedPoint(p1 == p2);
	}
};



void SomeTest()
{
	std::cout << std::boolalpha;
	std::cout << (FixedPoint(0.75) + FixedPoint(1.23) == FixedPoint(1.98)) << '\n'; // оба значения положительные, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(1.50) == FixedPoint(2.25)) << '\n'; // оба значения положительные, переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98)) << '\n'; // оба значения отрицательные, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25)) << '\n'; // оба значения отрицательные, переполнение
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.23) == FixedPoint(-0.48)) << '\n'; // второе значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.50) == FixedPoint(-0.75)) << '\n'; // второе значение отрицательное, возможно переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.23) == FixedPoint(0.48)) << '\n'; // первое значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.50) == FixedPoint(0.75)) << '\n'; // первое значение отрицательное, возможно переполнение
}

int main()
{
	SomeTest();

	FixedPoint a(-0.48);
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // введите 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}