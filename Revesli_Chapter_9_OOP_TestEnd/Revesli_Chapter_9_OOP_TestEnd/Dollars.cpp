#include "Dollars.h"

// ����������: ��� ������� �� �������� �� ������� ������, �� ������������� ������ Dollars!
Dollars operator+( Dollars& d1,  Dollars& d2)
{
	// ���������� ����������� Dollars � operator+(int, int).
	// ����� ��� �� ����� ������ ������ � �������� ������ ������ Dollars
	return Dollars(d1.getDollars() + d2.getDollars());
}