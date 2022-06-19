#include <iostream>
#include <vector>
#include <array>
class Shape
{
public:
	virtual std::ostream& print(std::ostream& out) const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Shape& p)
	{
		return p.print(out);
	}
	virtual ~Shape() {}
};

class Point
{
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;

public:
	Point(int x, int y, int z)
		: m_x(x), m_y(y), m_z(z)
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};

class Triangle : public Shape
{
private:
	Point m_p1;
	Point m_p2;
	Point m_p3;
public:
	Triangle(const Point& p1, const Point& p2, const Point& p3) : m_p1(p1), m_p2(p2), m_p3(p3) {};
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << m_p1 << ",  " << m_p2 << ",  " << m_p3;
		return out;
	}
};


class Circle : public Shape
{
private:
	Point m_p1;
	int m_radius;
public:
	Circle(const Point& p1, int radius) : m_p1(p1), m_radius(radius) {};

	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "(" << m_p1 << ", radius: " << m_radius << ")";
		return out;
	}
};




int main()
{
	std::vector<Shape*> v;
	Circle c1(Point(1, 2, 3), 7);
	Triangle t1(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9));
	Circle c2(Point(4, 5, 6), 3);
	v.push_back(&c1);
	v.push_back(&t1);
	v.push_back(&c2);

	for (int count = 0; count < v.size(); ++count)
	{
		std::cout << *v[count] << "\n";
	}


    return 0;
}