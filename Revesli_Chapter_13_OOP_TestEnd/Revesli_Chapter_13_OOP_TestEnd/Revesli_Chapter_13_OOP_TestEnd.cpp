
#include <iostream>
#include <cstring>
template <class T, class T2>
class Pair
{
private:
	T m_firstValue;
	T2 m_secondValue;
public:
	Pair(const T& firstValue, const T2& secondValue) : m_firstValue(firstValue), m_secondValue(secondValue) {};

	const T& first() const
	{
		return m_firstValue;
	}

	const T2& second() const
	{
		return m_secondValue;
	}
};


template <class T2>
class StringValuePair : public Pair<std::string, T2>
{
public:
	StringValuePair(const std::string& name, const T2& value) : Pair <std::string, T2>(name, value) {};
};

int main()
{
	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}