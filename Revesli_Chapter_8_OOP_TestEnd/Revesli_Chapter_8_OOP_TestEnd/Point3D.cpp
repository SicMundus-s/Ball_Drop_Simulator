

#include <iostream> // ��� std::cout
#include "Point3D.h" // ����� Point3D ��������� �����
#include "Vector3D.h" // ��� ��������� ������� moveByVector()

void Point3D::moveByVector(const Vector3D& v)
{
    // ��������� ���������� ������� � ��������������� ����������� �����
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}

void Point3D::print()
{
    std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}