#include "Dollars.h"

// Примечание: Эта функция не является ни методом класса, ни дружественной классу Dollars!
Dollars operator+( Dollars& d1,  Dollars& d2)
{
	// Используем конструктор Dollars и operator+(int, int).
	// Здесь нам не нужен прямой доступ к закрытым членам класса Dollars
	return Dollars(d1.getDollars() + d2.getDollars());
}