#include <iostream>
#include <cmath>
#include <Windows.h>
#include <conio.h>

using namespace std;

void sin_func()//5
{
	system("cls");

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	float x;

	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
	SelectObject(hDC, Pen);

	//OX
	MoveToEx(hDC, 0, 100, NULL);
	LineTo(hDC, 200, 100);
	//OY
	MoveToEx(hDC, 100, 0, NULL);
	LineTo(hDC, 100, 200);

	Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hDC, Pen);

	for (x = -3; x <= 3; x += 0.01) // От -П до П
	{
		MoveToEx(hDC, 10 * x + 100, -10 * sin(x) + 100, NULL);
		LineTo(hDC, 10 * x + 100, -10 * sin(x) + 100);
	}
	_getch();

}

int main() {

	sin_func();
}