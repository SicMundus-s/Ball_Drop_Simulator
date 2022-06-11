

#include <iostream> // дл€ std::cout
#include "Point3D.h" // класс Point3D определен здесь
#include "Vector3D.h" // дл€ параметра функции moveByVector()

void Point3D::moveByVector(const Vector3D& v)
{
    // ƒобавл€ем координаты вектора к соответствующим координатам точки
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}

void Point3D::print()
{
    std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}