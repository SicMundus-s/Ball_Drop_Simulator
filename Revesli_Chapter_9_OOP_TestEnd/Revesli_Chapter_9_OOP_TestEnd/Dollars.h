#pragma once
#ifndef DOLLARS_H
#define DOLLARS_H

class Dollars
{
private:
	int m_dollars;
public:
	Dollars(int dollars) : m_dollars(dollars) {};

	int getDollars()  { return m_dollars; }
};

Dollars operator+( Dollars& d1,  Dollars& d2);

#endif // !


