// Определение методов класса Vector3D

#include <iostream>
#include "Vector3D.h" // класс Vector3D определен в этом файле

void Vector3D::print()
{
    std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}